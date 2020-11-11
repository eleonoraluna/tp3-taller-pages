#ifndef SERVER_SRC_ROOTREADER_H_
#define SERVER_SRC_ROOTREADER_H_

#include <string>
#include <fstream>
#include "ResourceRepository.h"

class RootReader {
public:
	explicit RootReader(const std::string &filename);

	//abre el archivo donde se encuentra el recurso "/"
	//lanza una excepcion si no se pudo abrir
	void open_file();

	//lee el contenido del archivo y agrega el recurso "/" a
	//la lista de recursos junto su contenido
	void add_resource_to_repository(ResourceRepository &repository);
	virtual ~RootReader();
private:
	std::ifstream file;
};

#endif /* SERVER_SRC_ROOTREADER_H_ */
