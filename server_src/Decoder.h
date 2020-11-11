#ifndef SERVER_SRC_DECODER_H_
#define SERVER_SRC_DECODER_H_

#include <string>
#include <map>

class Decoder {
public:
	explicit Decoder();

	//parsea la primer linea del petitorio, la imprime y devuelve
	//el metodo y el recurso
	std::map<std::string,std::string> decode_method_and_resource(
			                                const std::string &petition);

    //parsea el contenido del petitorio y lo devuelve
	const std::string decode_body(const std::string &petition);

	virtual ~Decoder();
};

#endif /* SERVER_SRC_DECODER_H_ */
