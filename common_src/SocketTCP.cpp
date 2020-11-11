
#define _POSIX_C_SOURCE 200112L
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <string>
#include "SocketTCP.h"
#include "SocketTCPException.h"

#define MAX_CONNECTIONS 10

Socket_TCP::Socket_TCP(){
	this->fd=-1;
}

Socket_TCP::Socket_TCP(int fd){
	this->fd=fd;
}

Socket_TCP::Socket_TCP(const std::string &port){
	this->bind(port);
	this->listen();
}

void Socket_TCP::bind(const std::string &port){
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

void Socket_TCP::listen() const{
	 if (::listen(this->fd,MAX_CONNECTIONS)==-1){
		throw Socket_TCPException();
	 }
}

Socket_TCP Socket_TCP::accept() const{
	int fd=::accept(this->fd,NULL,NULL);
	if(fd==-1){
		throw Socket_TCPException();
	}
	return Socket_TCP(fd);
}

void Socket_TCP::connect(const std::string &name,const std::string &port){
	struct addrinfo hints;
	struct addrinfo *ai,*ai_list;
	bool connected=false;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_INET; //IPv4
	hints.ai_socktype=SOCK_STREAM; //TCP
	hints.ai_flags=0;

	if (getaddrinfo(name.c_str(),port.c_str(),&hints,&ai_list) !=0){
		throw Socket_TCPException();
	}
	for (ai=ai_list; ai!=NULL && !connected; ai=ai->ai_next){
	 if ((this->fd=socket(ai->ai_family,ai->ai_socktype,ai->ai_protocol))!=-1){
		 if (::connect(this->fd,ai->ai_addr,ai->ai_addrlen)!=-1){
			 connected=true;
		 }
	 }
	}
	freeaddrinfo(ai_list);
}

void Socket_TCP::recieve(char *buffer, int length) const{
	int pos=0;
	while(pos<length){
		int recieved=::recv(this->fd,&buffer[pos],length-pos,0);
		//sigo recibiendo hasta recibir todos los bytes
		if (recieved>0){
			pos=pos+recieved;
		//recibo 0 bytes. Hicieron un shutdown o llego al EOF
		} else if (recieved==0){
			throw Socket_TCPException();
		} else {//error en el rcv
			throw Socket_TCPException();
		}
	}
}

void Socket_TCP::send(const char *buffer, int length) const{
	 int pos=0;
	 while (pos<length){
		int sent=::send(this->fd,&buffer[pos],length-pos,MSG_NOSIGNAL);
		if (sent==0){
			throw Socket_TCPException();
		} else if (sent<0){//error en el send
			throw Socket_TCPException();
		} else {//sigo mandando hasta que se envien todos los bytes
			pos=pos+sent;
		}
	 }
}

Socket_TCP& Socket_TCP::operator =(Socket_TCP &&other){
	if (this ==&other){
		return *this;
	}
	if (this->fd!=-1){
		this->fd=other.fd;
		other.fd=-1;
	}
	return *this;
}

Socket_TCP::Socket_TCP(Socket_TCP&& other){
	this->fd=other.fd;
	other.fd=-1;
}

void Socket_TCP::stop(){
	 shutdown(this->fd,SHUT_RDWR);
	 close(this->fd);
	 this->fd=-1;
}

void Socket_TCP::shutdown_in_mode(int mode){
	 shutdown(this->fd,mode);
}

Socket_TCP::~Socket_TCP() {
	if(this->fd!=-1){
		shutdown(this->fd,SHUT_RDWR);
		close(this->fd);
		this->fd=-1;
	}
}

