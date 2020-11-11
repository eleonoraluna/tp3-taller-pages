#ifndef SERVER_SRC_PETITION_H_
#define SERVER_SRC_PETITION_H_

#include <string>
#include <atomic>
#include "../common_src/SocketTCP.h"
#include "server_Thread.h"
#include "Decoder.h"
#include "ResourceRepository.h"
#include "ResponseFactory.h"
#include "ServerResponse.h"

class Petition: public Thread {
public:
	explicit Petition(Socket_TCP socket,ResourceRepository &resources);

    //recibe la peticion deseada y la ejecuta
	void run() override;

	//indica si la peticion se sigue ejecutando o no
	bool is_still_alive() const;
	virtual ~Petition();

private:
	std::atomic<bool> isAlive;
	Socket_TCP socket;
	Decoder decoder;
	ResourceRepository &resources;
	ResponseFactory factory;

	//ejecuta la peticion
	void execute(const std::string &message);

	//devuelve la respuesta correspondiente del servidor
	ServerResponse* create_server_response(const std::string &method,
			          const std::string &resource,const std::string &petition);

	//chequea si se encuentra el recurso del que se quiere hacer un get
	//y a partir de eso crea las respuestas correspondientes del servidor
	ServerResponse* execute_get(const std::string &resource);

	//hace el post correspondiente y devuelve la respuesta del servidor
	ServerResponse* execute_post(const std::string &resource,
			                     const std::string &petition);

	//envia la respuesta del servidor mediante el socket
	void send_response(const std::string &server_response);
};

#endif /* SERVER_SRC_PETITION_H_ */
