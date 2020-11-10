#include "ResponseFactory.h"
#include "ForbiddenOperation.h"
#include "MethodNotAllowed.h"
#include "PostSuccessful.h"
#include "ResourceFound.h"
#include "ResourceNotFound.h"
#include <string>

ResponseFactory::ResponseFactory() {}

ServerResponse* ResponseFactory::create_forbidden_response(){
	return new ForbiddenOperation();
}

ServerResponse* ResponseFactory::create_method_not_allowed_response(
		                                          const std::string &name){
	return new MethodNotAllowed(name);
}

ServerResponse* ResponseFactory::create_resource_found_response(
		                                      const std::string &body){
	return new ResourceFound(body);
}

ServerResponse* ResponseFactory::create_resource_not_found_response(){
	return new ResourceNotFound();
}

ServerResponse* ResponseFactory::create_post_successful_response(
		                                       const std::string &body){
	return new PostSuccessful(body);
}

ResponseFactory::~ResponseFactory() {}

