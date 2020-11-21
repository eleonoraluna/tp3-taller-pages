#include "SocketAcceptor.h"
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <string>
#include "SocketTCPException.h"

#define MAX_CONNECTIONS 10

SocketAcceptor::SocketAcceptor(const std::string &port) {
	this->bind(port);
	this->listen();
}

void SocketAcceptor::bind(const std::string &port){
	struct addrinfo hints;
	struct addrinfo *ai,*ai_list;
	bool connected=false;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_INET; //IPv4
	hints.ai_socktype=SOCK_STREAM; //TCP
	hints.ai_flags=AI_PASSIVE; // AI_PASSIVE for server

	if (getaddrinfo(0,port.c_str(),&hints,&ai_list)!=0){
		throw Socket_TCPException();
	}
	for (ai=ai_list; ai!=NULL && !connected; ai=ai->ai_next){
	 if ((this->fd=socket(ai->ai_family,ai->ai_socktype,ai->ai_protocol))!=-1){
		 if (::bind(this->fd,ai->ai_addr,ai->ai_addrlen)!=-1){
			 connected=true;
		 }
	 }
	}
	freeaddrinfo(ai_list);
}

void SocketAcceptor::listen() const{
	 if (::listen(this->fd,MAX_CONNECTIONS)==-1){
		throw Socket_TCPException();
	 }
}

Socket_TCP SocketAcceptor::accept() const{
	int fd=::accept(this->fd,NULL,NULL);
	if(fd==-1){
		throw Socket_TCPException();
	}
	return Socket_TCP(fd);
}

void SocketAcceptor::stop(){
	 shutdown(this->fd,SHUT_RDWR);
	 close(this->fd);
	 this->fd=-1;
}

SocketAcceptor::~SocketAcceptor() {
	if(this->fd!=-1){
		shutdown(this->fd,SHUT_RDWR);
		close(this->fd);
		this->fd=-1;
	}
}

