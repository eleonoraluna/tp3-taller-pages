#include "Reader.h"
#include <iostream>
#include <string>
#include <sstream>

Reader::Reader(const std::string &name,const std::string &port):
protocol(name,port){}

void Reader::start(){
	 std::string input;
	 std::stringstream aux;
	 while (std::getline(std::cin,input)){
		aux<<input<<std::endl;
	 	std::string message=aux.str();
	 	this->protocol.send(message);
	 	std::stringstream().swap(aux);
	 }
	 this->protocol.stop_sending();
	 this->protocol.recv();
}

Reader::~Reader() {}

