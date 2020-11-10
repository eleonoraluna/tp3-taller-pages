#ifndef SERVER_SRC_RESOURCEREPOSITORY_H_
#define SERVER_SRC_RESOURCEREPOSITORY_H_
#include <string>
#include <map>
#include <mutex>

class ResourceRepository {
public:
	ResourceRepository();
	const std::string get(const std::string &resource);
	void post(std::string &resource,std::string &body);
	virtual ~ResourceRepository();
private:
	std::map<std::string,std::string> resources;
	std::mutex m;
};

#endif /* SERVER_SRC_RESOURCEREPOSITORY_H_ */
