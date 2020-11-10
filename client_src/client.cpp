#include <iostream>
#include <exception>
#include "../common_src/SocketTCPException.h"
#include "Reader.h"

#define ARGSCLIENT 3
#define OK 0

int main(int argc,char* argv[]){
	if(argc==ARGSCLIENT){
		try{
		 Reader reader(argv[1],argv[2]);
		 reader.start();
		}catch(const Socket_TCPException &e){
		  std::cout<<e.what()<<std::endl;
		}catch(const std::exception &e){
		  std::cout<<e.what()<<std::endl;
		}
	}
	//retorna siempre 0 como es pedido
	return OK;
}

