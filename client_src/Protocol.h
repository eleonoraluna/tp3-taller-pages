#ifndef CLIENT_SRC_PROTOCOL_H_
#define CLIENT_SRC_PROTOCOL_H_

#include <string>
#include "../common_src/SocketTCP.h"

class Protocol {
public:
	explicit Protocol(const std::string &name,const std::string &port);
	void send(const std::string &message);
	void stop_sending();
	void recv();
	virtual ~Protocol();

private:
	Socket_TCP socket;
};

#endif /* CLIENT_SRC_PROTOCOL_H_ */
