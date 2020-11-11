#ifndef SERVER_SRC_RESPONSEFACTORY_H_
#define SERVER_SRC_RESPONSEFACTORY_H_

#include "ServerResponse.h"
#include <string>

class ResponseFactory {
public:
	ResponseFactory();

	//crean las respuestas del servidor con los parámetros necesarios
	ServerResponse* create_forbidden_response();
	ServerResponse* create_method_not_allowed_response(const std::string &name);
	ServerResponse* create_resource_found_response(const std::string &body);
	ServerResponse* create_resource_not_found_response();
	ServerResponse* create_post_successful_response(const std::string &body);
	virtual ~ResponseFactory();
};

#endif /* SERVER_SRC_RESPONSEFACTORY_H_ */
