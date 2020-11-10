#ifndef SERVER_SRC_POSTSUCCESSFUL_H_
#define SERVER_SRC_POSTSUCCESSFUL_H_
#include "ServerResponse.h"
#include <string>

class PostSuccessful: public ServerResponse {
public:
	explicit PostSuccessful(const std::string &body);
	virtual std::string get_response() override;
	virtual ~PostSuccessful();
private:
	std::string body;
};

#endif /* SERVER_SRC_POSTSUCCESSFUL_H_ */
