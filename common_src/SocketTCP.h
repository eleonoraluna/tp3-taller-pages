#ifndef SOCKETTCP_H_
#define SOCKETTCP_H_
#include <string>
#include <atomic>

class Socket_TCP {
public:
	Socket_TCP();

	//hace un bind y listen
	explicit Socket_TCP(const std::string &port);
	void bind(const std::string &port);
	void listen() const;
	Socket_TCP accept() const;
	void connect(const std::string &name,const std::string &port);
	void recieve(char *buffer, int length) const;
	void send(const char *buffer, int length) const;
	void shutdown_in_mode(int mode);

	//hace un shutdown y close forzado para cerrar el socket aceptador
	void stop();
	Socket_TCP(Socket_TCP&& other);
	Socket_TCP& operator=(Socket_TCP&& other);
	Socket_TCP(const Socket_TCP&)=delete;
	Socket_TCP& operator=(const Socket_TCP&)=delete;
	virtual ~Socket_TCP();

private:
	int fd;
	explicit Socket_TCP(int fd);
	void freeAddrinfo(struct addrinfo *ai);
};

#endif /* COMMON_SOCKETTCP_H_ */
