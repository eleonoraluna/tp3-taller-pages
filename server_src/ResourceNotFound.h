#ifndef SERVER_SRC_RESOURCENOTFOUND_H_
#define SERVER_SRC_RESOURCENOTFOUND_H_

#include "ServerResponse.h"
#include <string>

class ResourceNotFound: public ServerResponse {
public:
	ResourceNotFound();
	virtual std::string get_response() override;
	virtual ~ResourceNotFound();
};

#endif /* SERVER_SRC_RESOURCENOTFOUND_H_ */
