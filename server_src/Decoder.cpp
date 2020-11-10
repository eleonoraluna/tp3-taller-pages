#include "Decoder.h"
#include <iostream>
#include <sstream>
#include <string>

Decoder::Decoder(ResourceRepository &resources):resources(resources) {}

std::string Decoder::decode_petition(std::string &petition){
	 std::string method,resource;
	 std::stringstream aux(petition);
	 char first_line[64];
	 aux.getline(first_line,64,'\n');
	 std::cout<<first_line<<std::endl;
	 std::stringstream line(first_line);
	 line>>method;
	 line>>resource;
	 ServerResponse* response=run_petition(method, resource, petition);
	 std::string message_to_send=response->get_response();
	 delete response;
	 return message_to_send;
}

ServerResponse* Decoder::run_petition(const std::string &method,
		                              std::string &resource,
									  std::string &petition){
	 if (method.compare("POST")!=0 && method.compare("GET")!=0){
		 return factory.create_method_not_allowed_response(method);
	 }else if (method.compare("POST")==0 && resource.compare("/")==0){
			 return factory.create_forbidden_response();
	 }else if (method.compare("POST")==0){
		 return this->run_post(resource, petition);
	 }else{
		 return is_get_valid(resource,petition);
	 }
}

ServerResponse* Decoder::run_post(std::string &resource,std::string &petition){
	 std::string body=this->decode_body(petition);
	 resources.post(resource, body);
	 return factory.create_post_successful_response(body);
}

ServerResponse* Decoder::is_get_valid(const std::string &resource,
		                              std::string &petition){
	const std::string body=this->resources.get(resource);
	if (body.empty()){
		return this->factory.create_resource_not_found_response();
	}else{
		return this->factory.create_resource_found_response(body);
	}
}

const std::string Decoder::decode_body(std::string &petition){
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

