#include "RootReader.h"
#include "FileErrorException.h"
#include <sstream>
#include <string>
#include <iostream>

RootReader::RootReader(const std::string &filename):file(filename) {}

void RootReader::open_file() {
	if (!this->file){
		throw FileErrorException();
	}
}

void RootReader::add_resource_to_repository(ResourceRepository &repository){
	 std::stringstream bodystream;
	 std::string line;
	 while (getline(file,line)){
		 bodystream<<line<<std::endl;
	 }
	 const std::string body=bodystream.str();
	 const std::string resource("/");
	 repository.post(resource, body);
}

RootReader::~RootReader() {}

