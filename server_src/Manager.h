#ifndef SERVER_SRC_MANAGER_H_
#define SERVER_SRC_MANAGER_H_

#include <string>
#include <vector>
#include <atomic>
#include "../common_src/SocketTCP.h"
#include "server_Thread.h"
#include "Petition.h"
#include "ResourceRepository.h"
#include "RootReader.h"

class Manager: public Thread {
public:
	explicit Manager(const std::string &port,const std::string &filename);
	void read_file();
	void run() override;
	void stop();
	virtual ~Manager();

private:
	ResourceRepository resources;
	RootReader reader;
	Socket_TCP main_socket;
	std::atomic<bool> isclosed;
	std::vector<Petition*> petitions;
	int accept_petition();
	void cleanup_finished_petitions();
};

#endif /* SERVER_SRC_MANAGER_H_ */
