#include "Petition.h"
#include "../common_src/SocketTCPException.h"
#include <vector>
#include <cstring>
#include <string>
#include <utility>
#include <map>

#define SHUT_WRITE 1
#define RECIEVE_BUFFER_SIZE 32

Petition::Petition(Socket_TCP socket,ResourceRepository &resources):
isAlive(true),socket(std::move(socket)),resources(resources) {}

bool Petition::is_still_alive() const{
	 return (this->isAlive);
}

void Petition::run(){
	 std::string message;
	 std::vector<char> vmessage(RECIEVE_BUFFER_SIZE);
	 try{
		 while (true){
			 this->socket.recieve(&vmessage[0],RECIEVE_BUFFER_SIZE);
			 message.append(vmessage.begin(),vmessage.end());
			 memset(vmessage.data(),0,vmessage.size());
		 }
	 }catch(const Socket_TCPException  &e){
		message.append(vmessage.begin(),vmessage.end());
		this->execute(message);
	 }
}

void Petition::execute(const std::string &message){
	 std::map<std::string,std::string> parameters=
			              this->decoder.decode_method_and_resource(message);
	 ServerResponse* server_response=this->create_server_response
			                              (parameters.at("method"),
			                               parameters.at("resource"),message);
	 std::string response=server_response->get_response();
	 this->send_response(response);
	 delete server_response;
}

ServerResponse* Petition::create_server_response(const std::string &method,
			          const std::string &resource,const std::string &petition){
	 if (method.compare("POST")!=0 && method.compare("GET")!=0){
		 return factory.create_method_not_allowed_response(method);
	 }else if (method.compare("POST")==0 && resource.compare("/")==0){
			 return factory.create_forbidden_response();
	 }else if (method.compare("POST")==0){
		 return this->execute_post(resource, petition);
	 }else{
		 return execute_get(resource);
	 }
}

ServerResponse* Petition::execute_post(const std::string &resource,
		                               const std::string &petition){
	 const std::string body=this->decoder.decode_body(petition);
	 resources.post(resource, body);
	 return factory.create_post_successful_response(body);
}

ServerResponse* Petition::execute_get(const std::string &resource){
	const std::string body=this->resources.get(resource);
	if (body.empty()){
		return this->factory.create_resource_not_found_response();
	}else{
		return this->factory.create_resource_found_response(body);
	}
}

void Petition::send_response(const std::string &server_response){
	 this->socket.send(server_response.data(),server_response.size());
	 this->socket.shutdown_in_mode(SHUT_WRITE);
	 this->isAlive=false;
}

Petition::~Petition() {}

