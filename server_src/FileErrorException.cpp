#include "FileErrorException.h"

FileErrorException::FileErrorException() {}

const char* FileErrorException:: what() const throw(){
	  return "Error opening file\n";
}

FileErrorException::~FileErrorException() {}

