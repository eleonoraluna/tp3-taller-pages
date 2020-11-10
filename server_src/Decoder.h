#ifndef SERVER_SRC_DECODER_H_
#define SERVER_SRC_DECODER_H_

#include "ResponseFactory.h"
#include "ServerResponse.h"
#include "ResourceRepository.h"
#include <string>

class Decoder {
public:
	explicit Decoder(ResourceRepository &resources);
	std::string decode_petition(std::string &petition);
	virtual ~Decoder();
private:
	ResponseFactory factory;
	ResourceRepository &resources;
	const std::string decode_body(std::string &petition);
	ServerResponse* run_petition(const std::string &method,std::string &resource
			                    ,std::string &petition);
	ServerResponse* is_get_valid(const std::string &resource,std::string &petition);
	ServerResponse* run_post(std::string &resource,std::string &petition);
};

#endif /* SERVER_SRC_DECODER_H_ */
