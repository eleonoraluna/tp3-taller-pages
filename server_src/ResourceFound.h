#ifndef SERVER_SRC_RESOURCEFOUND_H_
#define SERVER_SRC_RESOURCEFOUND_H_
#include "ServerResponse.h"
#include <string>

class ResourceFound: public ServerResponse {
public:
	explicit ResourceFound(const std::string &body);
	virtual std::string get_response() override;
	virtual ~ResourceFound();
private:
	std::string body;
};

#endif /* SERVER_SRC_RESOURCEFOUND_H_ */
