/*
 * TcpLinkClient.cpp
 *
 *  Created on: 12 maj 2016
 *      Author: wojtek
 */

#include "TcpLinkClient.h"
#include <string>

#include "../../Exception/Exception.h"
#include "../../Logger/Logger.h"
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


using std::string;
namespace iot {

TcpLinkClient::TcpLinkClient(TcpLink* server, int connected_socket, uint32_t ip, uint16_t port) {
	this->_server = server;
	this->_connected_socket = connected_socket;
	this->_ip = ip;
	this->_port = port;
}

void TcpLinkClient::connect() {
	this->start();
	this->_thread = std::thread(TcpLinkClient::run,shared_from_this());
}

void TcpLinkClient::run(std::shared_ptr<TcpLinkClient> client) {
	LoggerFactory lf;
	auto log =  lf.createProduct();
	log->debug("TCPServerClient: Client running");
	client->putline("Device: ");
	uint32_t addr = 0;
	string id = client->getline(false);
	try {
		addr = std::stoul(id);
	} catch(std::invalid_argument& ex) {
		log->warn("Device with unknown id: " + id);
		return;
	}

	log->debug("TCPServerClient: Device: "+std::to_string(addr));

	client->putline("Password: ");
	log->debug("TCPServerClient: Password: "+client->getline(true));

	string c("");
	do {
		client->putline("Cmd: ");
		try {
			c = client->getline();
		} catch (Exception& e) {
			log->error(e.getMsg());
			break;
		}
		auto pck = std::make_shared<Spacket>();

		pck->dev.addr = addr;
		pck->dev.network_conf="TcpLink"; // stub
		pck->message = c;
		client->getServer()->read(pck);
		//log->debug("TcpLink: new msg: "+c);
		// TODO write command interpretation here
	} while (client->is_running());
}


void TcpLinkClient::disconnect() {
	LoggerFactory lf;
	auto log =  lf.createProduct();
	log->debug("TCPServerClient: Client disconnecting");
	shutdown(this->_connected_socket, SHUT_RDWR);
	this->_thread.join();
}

void TcpLinkClient::putline(std::string str) {
	send(this->_connected_socket, str.c_str(), str.length(), 0);
}

string TcpLinkClient::getline(bool asterisks) {
	string line("");
	char c;
	size_t rxbytes;
	do {
		rxbytes = recv(this->_connected_socket, &c, 1, 0);
		if (rxbytes == 1 && c >= 32) {
			line += c;
			if (asterisks)
				c = '*';
			//send(this->_connected_socket, &c, 1, 0); //echo
		}
		if (rxbytes == -1) {
			this->stop();
			throw Exception("client disconnected");
		}
	} while (rxbytes == 1 && c != '\r');
	return line;
}

TcpLinkClient::~TcpLinkClient() {
	disconnect();
}

} /* namespace iot */


