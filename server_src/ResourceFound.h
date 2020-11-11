#ifndef SERVER_SRC_RESOURCEFOUND_H_
#define SERVER_SRC_RESOURCEFOUND_H_

#include <string>
#include "ServerResponse.h"

class ResourceFound: public ServerResponse {
public:
	explicit ResourceFound(const std::string &body);
	virtual std::string get_response() override;
	virtual ~ResourceFound();
private:
	std::string body;
	static const char first_line[];
};

#endif /* SERVER_SRC_RESOURCEFOUND_H_ */
