#include <iostream>
#include <exception>
#include "Header.h"

//definition of a method that checks if input is integer, if not it throws an exception
void Employee::isInputValid(int& is_int) {
	//checking if input is integer
	try {
		if (!(std::cin >> is_int)) {  //if input is not valid, throw this exception
			throw std::invalid_argument("Input is not an integer\n");
		}
	}
	catch (const std::exception& e) { //here we catch the exception and print what it states to the user
		system("cls");
		std::cerr << "Error: " << e.what();  //using cerr to display an exception
		exit(0);  //stopping the execution of program after invalid input
	}
	system("cls");
}