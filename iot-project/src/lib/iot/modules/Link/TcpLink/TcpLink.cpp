/*
 * TcpLink.cpp
 *
 *  Created on: 12 maj 2016
 *      Author: wojtek
 */

#include "TcpLink.h"
#include <sstream>

#include "../../Logger/LoggerFactory.h"

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <WinSock2.h>
	#include <Ws2tcpip.h>
	#define SHUT_RDWR SD_BOTH
	typedef int	socklen_t;
	//void sleep(uint32_t s);
#else
	#include <arpa/inet.h>
	#include <sys/socket.h>
	#include <unistd.h>
#endif

namespace iot {

TcpLink::TcpLink() {
	this->setUniqueName("TcpLink");
	this->_running = false;
}

std::shared_ptr<Logger> TcpLink::log() {
	LoggerFactory lf;
	return lf.createProduct();
}

bool TcpLink::connect(std::string conf, LinkMediator* mediator) {
	this->_port = std::stoul(conf);
	this->_mediator = mediator;
	this->setRunning(true);
	this->_thread = std::thread(TcpLink::run,this);
	return true;
}

bool TcpLink::disconnect() {
	this->stop();
	return true;
}

bool TcpLink::send(std::shared_ptr<Spacket> packet) {
	return true;
}

bool TcpLink::read(std::shared_ptr<Spacket> packet) {
	this->_mediator->notify(packet);
	return true;
}

void TcpLink::setRunning(bool runnig) {
	this->_running = runnig;
}

bool TcpLink::isRunning() {
	return this->_running.load();
}

void TcpLink::run(TcpLink* link) {
	link->log()->debug("TCPServer::run");
	link->_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(link->_socket == -1) {
		link->stop();
		return;
	}

	sockaddr_in local;
	memset((char*) &local, 0, sizeof(local));
	local.sin_family = AF_INET;
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	local.sin_port = htons(link->_port);
	if (bind(link->_socket, (const sockaddr*) &local, sizeof(local))
			== -1) {
		link->log()->error("TCPServer: problem: bind");
		link->stop();
		return;
	}
	if (listen(link->_socket, 10) == -1) {
		link->log()->error("TCPServer: problem: listen");
		link->stop();
		return;
	}

	while (link->isRunning()) {
		sockaddr_in remote;
		socklen_t sockaddrlen = sizeof(remote);
		int client_socket = accept(link->_socket, (sockaddr*) &remote,
				&sockaddrlen);
		if (client_socket != -1) {

			std::stringstream ss;
			ss << "client connected: " << remote.sin_addr.s_addr << " : "
					<< remote.sin_port;
			link->log()->debug(ss.str());
			auto client = std::make_shared<TcpLinkClient>(link, client_socket,
					remote.sin_addr.s_addr, remote.sin_port);
			link->addClient(client);
			client->connect();

		} else {
			link->log()->error("TCPServer: Accept error");
			link->stop();
		}
	}

	for(auto &t : link->_clients){
		t->stop();
		t->disconnect();
		link->removeClient(t);
	}
	link->log()->error("TCPServer: Closing");
}

void TcpLink::stop() {
	this->log()->debug("TCPServer: stopping");
	shutdown(this->_socket, SHUT_RDWR);
	this->setRunning(false);
}

void TcpLink::addClient(std::shared_ptr<TcpLinkClient> client) {
	this->_clients.push_back(client);
	this->log()->debug("TCPServer: Client added");
}

void TcpLink::removeClient(std::shared_ptr<TcpLinkClient> client) {
	this->log()->debug("TCPServer: Removing client");
	for (auto it = this->_clients.begin(); it != this->_clients.end(); ++it) {
		if (*it == client) {
			this->_clients.erase(it);
			return;
		}
	}
}

TcpLink::~TcpLink() {
	if(this->isRunning()) this->stop();
}

} /* namespace iot */
