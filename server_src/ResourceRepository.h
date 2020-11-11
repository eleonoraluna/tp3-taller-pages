#ifndef SERVER_SRC_RESOURCEREPOSITORY_H_
#define SERVER_SRC_RESOURCEREPOSITORY_H_

#include <string>
#include <map>
#include <mutex>

class ResourceRepository {
public:
	ResourceRepository();

	//devuelve el contenido del recurso indicado
	const std::string get(const std::string &resource);

	//guarda el recurso correspondiente con el contenido indicado
	void post(const std::string &resource,const std::string &body);

	virtual ~ResourceRepository();
private:
	std::map<std::string,std::string> resources;
	std::mutex m;
};

#endif /* SERVER_SRC_RESOURCEREPOSITORY_H_ */
