#ifndef SERVER_SRC_METHODNOTALLOWED_H_
#define SERVER_SRC_METHODNOTALLOWED_H_

#include <string>
#include "ServerResponse.h"

class MethodNotAllowed: public ServerResponse{
public:
	explicit MethodNotAllowed(const std::string &name);
	virtual std::string get_response() override;
	virtual ~MethodNotAllowed();
private:
	std::string name;
};

#endif /* SERVER_SRC_METHODNOTALLOWED_H_ */
