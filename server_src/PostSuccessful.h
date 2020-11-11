#ifndef SERVER_SRC_POSTSUCCESSFUL_H_
#define SERVER_SRC_POSTSUCCESSFUL_H_

#include <string>
#include "ServerResponse.h"

class PostSuccessful: public ServerResponse {
public:
	explicit PostSuccessful(const std::string &body);
	virtual std::string get_response() override;
	virtual ~PostSuccessful();
private:
	std::string body;
	static const char first_line[];
};

#endif /* SERVER_SRC_POSTSUCCESSFUL_H_ */
