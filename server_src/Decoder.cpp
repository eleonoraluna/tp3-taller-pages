#include "Decoder.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>

#define MAX_BUFFER_SIZE 64

Decoder::Decoder() {}

std::map<std::string,std::string> Decoder::decode_method_and_resource(
		                                         const std::string &petition){
	 std::string method,resource;
	 std::stringstream aux(petition);
	 char first_line[MAX_BUFFER_SIZE];
	 aux.getline(first_line,MAX_BUFFER_SIZE,'\n');
	 std::cout<<first_line<<std::endl;
	 std::stringstream line(first_line);
	 line>>method;
	 line>>resource;
	 std::map<std::string,std::string> parameters;
	 parameters.emplace("method",method);
	 parameters.emplace("resource",resource);
	 return parameters;
}

const std::string Decoder::decode_body(const std::string &petition){
	  std::stringstream aux(petition);
	  std::stringstream bodystream;
	  std::string line;
	  while (getline(aux,line)){
		 if (line.empty()){
			 break;
		 }
	  }
	  while (getline(aux,line)){
		 bodystream<<line<<std::endl;
	  }
	  std::string body=bodystream.str();
	  return body;
}

Decoder::~Decoder() {}

