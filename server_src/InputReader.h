#ifndef SERVER_SRC_INPUTREADER_H_
#define SERVER_SRC_INPUTREADER_H_

#include "Manager.h"

class InputReader {
public:
	explicit InputReader(Manager &manager);
	void start();
	virtual ~InputReader();

private:
	Manager &manager;
};

#endif /* SERVER_SRC_INPUTREADER_H_ */
