#include "ResourceFound.h"
#include <string>

const char ResourceFound::first_line[]="HTTP/1.1 200 OK\nContent-Type: "
		                            "text/html\n\n";

ResourceFound::ResourceFound(const std::string &body):body(body) {}

std::string ResourceFound::get_response(){
	return(first_line+body);
}

ResourceFound::~ResourceFound() {}

