/*
 * TcpLink.h
 *
 *  Created on: 12 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LINK_TCPLINK_TCPLINK_H_
#define LIB_IOT_MODULES_LINK_TCPLINK_TCPLINK_H_

#include "../Link.h"
#include "TcpLinkClient.h"
#include <atomic>
#include <vector>
#include <memory>
#include <thread>
#include "../../Logger/Logger.h"

namespace iot {

class TcpLinkClient;

class TcpLink: public Link {
private:
	volatile int _socket = -1;
	uint16_t _port = 0;
	std::vector<std::shared_ptr<TcpLinkClient>> _clients;
	std::atomic<bool> _running;
	std::thread _thread;
	LinkMediator* _mediator = nullptr;
protected:
	std::shared_ptr<Logger> log();

public:
	TcpLink();
	void setRunning(bool runnig);
	virtual bool isRunning();
	virtual bool connect(std::string conf, LinkMediator* mediator);
	virtual bool disconnect();
	virtual bool send(std::shared_ptr<Spacket> packet);
	virtual bool read(std::shared_ptr<Spacket> packet);
	static void run(TcpLink* link);
	void stop();
	virtual void addClient(std::shared_ptr<TcpLinkClient> client);
	virtual void removeClient(std::shared_ptr<TcpLinkClient> client);
	virtual ~TcpLink();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_TCPLINK_TCPLINK_H_ */
