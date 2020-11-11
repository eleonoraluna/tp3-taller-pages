#ifndef SERVER_SRC_INPUTREADER_H_
#define SERVER_SRC_INPUTREADER_H_

#include "Manager.h"

class InputReader {
public:
	explicit InputReader(Manager &manager);

	//Hace correr al manager mientras espera por entrada una "q" que
	//indique que no se aceptan nuevas conexiones frenando
	//al manager y esperando a que termine
	void start();
	virtual ~InputReader();

private:
	Manager &manager;
};

#endif /* SERVER_SRC_INPUTREADER_H_ */
