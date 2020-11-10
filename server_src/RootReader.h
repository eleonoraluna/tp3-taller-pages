#ifndef SERVER_SRC_ROOTREADER_H_
#define SERVER_SRC_ROOTREADER_H_
#include <string>
#include <fstream>
#include "ResourceRepository.h"

class RootReader {
public:
	explicit RootReader(const std::string &filename);
	void open_file();
	void add_resource_to_repository(ResourceRepository &repository);
	virtual ~RootReader();
private:
	std::ifstream file;
};

#endif /* SERVER_SRC_ROOTREADER_H_ */
