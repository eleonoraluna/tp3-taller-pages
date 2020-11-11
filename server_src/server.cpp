#include <iostream>
#include <exception>
#include "../common_src/SocketTCPException.h"
#include "FileErrorException.h"
#include "Manager.h"
#include "InputReader.h"

#define ARGSSERVER 3
#define ERROR 1
#define OK 0

int main(int argc,char* argv[]){
	if(argc==ARGSSERVER){
	   try{
		   Manager manager(argv[1],argv[2]);
		   InputReader reader(manager);
		   reader.start();
	      }catch(const FileErrorException &e){
	  		  std::cout<<e.what()<<std::endl;
	  		  return ERROR;
	      }catch(const Socket_TCPException &e){
			  std::cout<<e.what()<<std::endl;
			  return ERROR;
	      }catch(const std::exception &e){
			  std::cout<<e.what()<<std::endl;
			  return ERROR;
	      }catch(...){
	    	  std::cout<<"error desconocido"<<std::endl;
	    	  return ERROR;
	      }
	}else{
		  std::cout<<"Error: argumentos inválidos."<<std::endl;
		  return ERROR;
	}
	return OK;
}




