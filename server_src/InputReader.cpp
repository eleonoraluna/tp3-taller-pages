#include "InputReader.h"
#include <iostream>

InputReader::InputReader(Manager &manager):manager(manager) {}

void InputReader::start(){
	 manager.read_file();
	 manager.start();
	 char exit=0;
	 while (exit!='q'){
	 std::cin>>exit;
	 }
	 manager.stop();
	 manager.join();
}

InputReader::~InputReader() {}

