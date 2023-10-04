#include <iostream>
#include <fstream>
#include "Header.h" 

using std::cout;
using std::cin;
using std::string;

void Employee::saveInformation(std::vector<std::string>& EmployeeReason, std::vector<std::string>& EmployeeInfo) {
	//This function stores the content of our two vectors to a notepad file called EmployeeVectors

	//1.Creating the file and opening it
	std::fstream File;
	File.open("EmployeePrivateInformation.txt", std::ios::out);

	if (!File.is_open()) {  //if file did not open, call this function and throw an exception
		hasFileOppened(false);
	}
	//2.Writing to that file/adding the content of the vectors to it
	if (File.is_open()) {
		File << "1.Employee's reason for being here: \n";
		for (string current_line : EmployeeReason)  //using range based loop to write to the file
			File << current_line << " \n";

		File << "\n2.Private information regarding employee: \n";
		for (string current_line : EmployeeInfo)
			File << current_line << " \n";
	}

	//3.Closing the file
	File.close();

}