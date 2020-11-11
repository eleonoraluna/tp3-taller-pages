#include "MethodNotAllowed.h"
#include <string>

static const std::string first_line="HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
static const std::string second_line=" es un comando desconocido\n";

MethodNotAllowed::MethodNotAllowed(const std::string &name):name(name) {}

std::string MethodNotAllowed::get_response(){
	return(first_line+name+second_line);
}

MethodNotAllowed::~MethodNotAllowed() {}

