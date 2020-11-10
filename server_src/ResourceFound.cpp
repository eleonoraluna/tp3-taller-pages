#include "ResourceFound.h"
#include <string>

#define first_line "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"

ResourceFound::ResourceFound(const std::string &body):body(body) {}

std::string ResourceFound::get_response(){
	return(first_line+body);
}

ResourceFound::~ResourceFound() {}

