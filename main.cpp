#include <iostream>
#include <unistd.h>

#include "inputpin.hpp"
#include "outputpin.hpp"


int main() {
	InputPin photosensor(17);

	OutputPin lightA(8);
	OutputPin lightB(9);

	while(true) {
		sleep(1);

		if(photosensor) {
			std::cout << "Switching lights!";
			lightB = !(lightA = !lightA); // swap bool values
		}
	}
}