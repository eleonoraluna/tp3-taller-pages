#ifndef COMMON_SRC_SOCKETACCEPTOR_H_
#define COMMON_SRC_SOCKETACCEPTOR_H_

#include <string>
#include "SocketTCP.h"

class SocketAcceptor {
public:
	//hace un bind y listen
	explicit SocketAcceptor(const std::string &port);

	//crea sockets clientes
	Socket_TCP accept() const;

	//hace un shutdown y close forzado para cerrar el socket aceptador
	void stop();
	virtual ~SocketAcceptor();
private:
	int fd;
	void bind(const std::string &port);
	void listen() const;
};

#endif /* COMMON_SRC_SOCKETACCEPTOR_H_ */
