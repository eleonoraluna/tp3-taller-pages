#include "PostSuccessful.h"
#include <string>

#define first_line "HTTP/1.1 200 OK\n\n"

PostSuccessful::PostSuccessful(const std::string &body):body(body){}

std::string PostSuccessful::get_response(){
	return(first_line+body);
}

PostSuccessful::~PostSuccessful() {}

