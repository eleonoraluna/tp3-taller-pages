#include "ForbiddenOperation.h"
#include <string>

const char ForbiddenOperation::response[]="HTTP/1.1 403 FORBIDDEN\n\n";

ForbiddenOperation::ForbiddenOperation() {}

std::string ForbiddenOperation::get_response(){
	return(response);
}

ForbiddenOperation::~ForbiddenOperation() {}

