/*
 * TcpLinkClient.h
 *
 *  Created on: 12 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LINK_TCPLINK_TCPLINKCLIENT_H_
#define LIB_IOT_MODULES_LINK_TCPLINK_TCPLINKCLIENT_H_

#include "TcpLink.h"
#include <atomic>
#include <memory>
#include <thread>

namespace iot {

class TcpLink;

class TcpLinkClient: public std::enable_shared_from_this<TcpLinkClient>{
private:
	std::atomic<bool> _is_running;
	uint32_t _ip;
	uint16_t _port;
	int _connected_socket;
	std::thread _thread;
	TcpLink* _server;
protected:
    static void run(std::shared_ptr<TcpLinkClient> client);
public:
	TcpLinkClient(TcpLink* server, int connected_socket, uint32_t ip, uint16_t port);
	virtual ~TcpLinkClient();
	virtual void connect();
	virtual void disconnect();
	virtual void putline(std::string str);
	virtual std::string getline(bool asterisks = false);

	virtual bool is_running() {
		return _is_running.load();
	}
	;
	virtual void stop() {
		_is_running = false;
	}
	virtual void start() {
		_is_running = true;
	}
	TcpLink* getServer() {
		return _server;
	}
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_TCPLINK_TCPLINKCLIENT_H_ */
