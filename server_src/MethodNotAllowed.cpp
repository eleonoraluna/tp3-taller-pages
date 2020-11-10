#include "MethodNotAllowed.h"
#include <string>

#define first_line "HTTP/1.1 405 METHOD NOT ALLOWED\n\n"
#define second_line " es un comando desconocido\n"

MethodNotAllowed::MethodNotAllowed(const std::string &name):name(name) {}

std::string MethodNotAllowed::get_response(){
	return(first_line+name+second_line);
}

MethodNotAllowed::~MethodNotAllowed() {}

