#ifndef SERVER_SRC_FORBIDDENOPERATION_H_
#define SERVER_SRC_FORBIDDENOPERATION_H_

#include "ServerResponse.h"
#include <string>

class ForbiddenOperation: public ServerResponse {
public:
	ForbiddenOperation();
	virtual std::string get_response() override;
	virtual ~ForbiddenOperation();
private:
	static const char response[];
};

#endif /* SERVER_SRC_FORBIDDENOPERATION_H_ */
