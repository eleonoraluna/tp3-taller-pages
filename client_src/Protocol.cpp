#include "Protocol.h"
#include "../common_src/SocketTCPException.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define SHUT_WRITE 1

Protocol::Protocol(const std::string &name,const std::string &port) {
	this->socket.connect(name, port);
}

void Protocol::send(const std::string &message){
	 this->socket.send(message.data(),message.size());
}

void Protocol::stop_sending(){
	 this->socket.shutdown_in_mode(SHUT_WRITE);
}

void Protocol::recv(){
	 std::string message;
	 int length=32;
	 std::vector<char> vmessage(length);
	 try{
		 while (true){
			this->socket.recieve(&vmessage[0],length);
		    message.append(vmessage.begin(),vmessage.end());
		    memset(vmessage.data(),0,vmessage.size());
		 }
	  }catch(const Socket_TCPException  &e){
			message.append(vmessage.begin(),vmessage.end());
			std::cout<<message.data();
	  }
}

Protocol::~Protocol() {}

