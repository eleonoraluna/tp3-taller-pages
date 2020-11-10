#include "Manager.h"
#include "../common_src/SocketTCPException.h"
#include <string>
#include <vector>
#include <utility>

#define ERROR_ON_ACCEPT 1
#define OK 0

Manager::Manager(const std::string &port,const std::string &filename):
reader(filename),main_socket(port),isclosed(false){}

void Manager::run(){
	 this->reader.open_file();
	 this->reader.add_resource_to_repository(resources);
	 while (!this->isclosed){
		  if (this->accept_petition()!=ERROR_ON_ACCEPT){
			  this->cleanup_finished_petitions();
		  }
	 }
}

int Manager::accept_petition(){
	try{
		Socket_TCP socket=this->main_socket.accept();
		Petition* p=new Petition(std::move(socket),resources);
		this->petitions.push_back(p);
		p->start();
		}catch(const Socket_TCPException &e){
		    return ERROR_ON_ACCEPT;
		}
	return OK;
}

void Manager::cleanup_finished_petitions(){
	 std::vector<Petition*> aux;
	 for (Petition* p:this->petitions){
		if (!p->is_still_alive()){
		    p->join();
			delete(p);
		}else{
			aux.push_back(p);
		}
	 }
	 this->petitions.swap(aux);
}

void Manager::stop(){
	 this->isclosed=true;
	 this->main_socket.stop();
}

Manager::~Manager() {
	for (Petition* p:this->petitions){
		 p->join();
		 delete(p);
	}
}

