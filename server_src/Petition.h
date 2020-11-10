#ifndef SERVER_SRC_PETITION_H_
#define SERVER_SRC_PETITION_H_

#include "server_Thread.h"
#include "Decoder.h"
#include "../common_src/SocketTCP.h"
#include "ResourceRepository.h"

class Petition: public Thread {
public:
	explicit Petition(Socket_TCP socket,ResourceRepository &resources);
	void run() override;
	bool is_still_alive() const;
	virtual ~Petition();

private:
	std::atomic<bool> isAlive;
	Socket_TCP socket;
	Decoder decoder;
};

#endif /* SERVER_SRC_PETITION_H_ */
