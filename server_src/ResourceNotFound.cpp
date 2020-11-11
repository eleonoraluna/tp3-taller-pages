#include "ResourceNotFound.h"
#include <string>

const char ResourceNotFound::response[]="HTTP/1.1 404 NOT FOUND\n";

ResourceNotFound::ResourceNotFound() {}

std::string ResourceNotFound::get_response(){
	return response;
}

ResourceNotFound::~ResourceNotFound() {}

