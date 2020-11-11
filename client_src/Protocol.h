#ifndef CLIENT_SRC_PROTOCOL_H_
#define CLIENT_SRC_PROTOCOL_H_

#include <string>
#include "../common_src/SocketTCP.h"

class Protocol {
public:
	explicit Protocol(const std::string &name,const std::string &port);

	//envia mensaje al servidor mediante el socket
	void send(const std::string &message);

	//cierra el canal de escritura del socket
	void stop_sending();

	//recibe la respuesta del servidor
	void recv();

	virtual ~Protocol();

private:
	Socket_TCP socket;
};

#endif /* CLIENT_SRC_PROTOCOL_H_ */
