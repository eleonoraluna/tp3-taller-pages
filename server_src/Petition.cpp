#include "Petition.h"
#include <iostream>
#include "../common_src/SocketTCPException.h"
#include <vector>
#include <cstring>
#include <string>
#include <utility>

#define SHUT_WRITE 1

// cppcheck-suppress constParameter
Petition::Petition(Socket_TCP socket,ResourceRepository &resources):
isAlive(true),socket(std::move(socket)),decoder(resources) {}

bool Petition::is_still_alive() const{
	 return (this->isAlive);
}

void Petition::run(){
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
	 }
	 std::string server_response=this->decoder.decode_petition(message);
	 this->socket.send(server_response.data(),server_response.size());
	 this->socket.shutdown_in_mode(SHUT_WRITE);
	 this->isAlive=false;
}

Petition::~Petition() {}

