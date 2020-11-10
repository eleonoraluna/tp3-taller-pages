#ifndef SERVER_SRC_SERVERRESPONSE_H_
#define SERVER_SRC_SERVERRESPONSE_H_
#include <string>

class ServerResponse {
public:
	ServerResponse();
	virtual std::string get_response()=0;
	virtual ~ServerResponse();
};

#endif /* SERVER_SRC_SERVERRESPONSE_H_ */
