#ifndef INPUTPIN_HPP
#define INPUTPIN_HPP

#include <fstream>
#include <sstream>
#include <string>


class InputPin {

private:
	std::ifstream fin;

public:
	InputPin(int pinID) {
		// open fin
		std::stringstream pinPath;
		pinPath << "/sys/class/gpio/gpio" << pinID << "/value";
		fin.open(pinPath.str().c_str(), std::ios::in);
	}

	// read
	operator bool() {
		fin.seekg(0);
		return fin.get() == '0';
	}

};


#endif