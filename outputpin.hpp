#ifndef OUTPUTPIN_HPP
#define OUTPUTPIN_HPP

#include <fstream>
#include <sstream>
#include <string>


class OutputPin {

private:
	std::fstream fout;

public:
	OutputPin(int pinID) {
		// open fout
		std::stringstream pinPath;
		pinPath << "/sys/class/gpio/gpio" << pinID << "/value";
		fout.open(pinPath.str().c_str(), std::ios::in | std::ios::out);
	}

	// write
	bool operator=(bool value) {
		fout.seekp(0);
		fout.put(value ? '1' : '0');
		return value;
	}

	// read
	operator bool() {
		fout.seekg(0);
		return fout.get() == '0';
	}

};


#endif