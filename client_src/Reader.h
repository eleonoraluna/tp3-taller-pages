#ifndef CLIENT_SRC_READER_H_
#define CLIENT_SRC_READER_H_

#include "Protocol.h"
#include <string>

class Reader {
public:
	explicit Reader(const std::string &name,const std::string &port);
	void start();
	virtual ~Reader();

private:
	Protocol protocol;
};

#endif /* CLIENT_SRC_READER_H_ */
