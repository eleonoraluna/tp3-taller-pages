#include "ResourceRepository.h"
#include <exception>
#include <string>

ResourceRepository::ResourceRepository() {}

const std::string ResourceRepository::get(const std::string &resource){
	 std::unique_lock<std::mutex> lock(this->m);
	 std::string body;
	 try{
		 body=this->resources.at(resource);
	 }catch(const std::exception &e){}
	 return body;
}

void ResourceRepository::post(const std::string &resource,
		                      const std::string &body){
	 std::unique_lock<std::mutex> lock(this->m);
	 this->resources.emplace(resource,body);
}

ResourceRepository::~ResourceRepository() {}

