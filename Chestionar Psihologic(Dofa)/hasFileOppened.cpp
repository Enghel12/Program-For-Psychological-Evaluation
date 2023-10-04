#include <iostream>
#include <exception>
#include "Header.h"

//this method will throw an exception if we try to open a file and it doesn't work
void Employee::hasFileOppened(bool hasOppened) {

	//if the file did not open, throw an exception, print it and stop the execution of program
	try {
		if (!hasOppened)
			throw std::invalid_argument("File did not open or it does not exist");
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
		exit(0);
	}
}