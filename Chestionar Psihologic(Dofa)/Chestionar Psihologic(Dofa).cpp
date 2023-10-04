#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <list>  //including all the libraries that I think I will need
#include <string>
#include <conio.h>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <map>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <exception>
#include "Header.h"

typedef long l;
typedef long long ll;

using std::vector;
using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::list;
using std::stringstream;

//declaring the only global variable of this progam(to avoid bugs)
bool employee_has_real_problem = false;

//function 1 checks if input is integer, if not, it throws an exception
void checkInteger(int &main_input) {
	//variable is called main input because it referse to input from main function
	
	try {
		if (!(cin >> main_input)) //if the input is not int, throw an exception
			throw std::invalid_argument("Error, number entered is not an integer!");
	}
	catch (const std::exception& e) {
		system("cls");
		std::cerr << e.what();
		cout << "\n\nExiting.\n\n";
		exit(0);
	}
}

int main()
{
	

	//1.creating a pointer that points to an object located in heap memory
	AccessEmployee* use_function = new AccessEmployee;
	use_function->AccessProtectedFunctions();   //accesing a function of a child class
	delete use_function;  //freeing up the memory used by this pointer

	//End of the program, here we print the last message to the console
	cout << "\nEverything is saved, you can close the program now\n";
	cout << "\nThank you for using DOFA, press 1 to exit the program or enter the code if you are a supervisor: \n";
	int user_choice = 0, supervisor_input = 0;
	checkInteger(user_choice);
	system("cls");

	//The program continues here only if the user if a supervisor, special input will be required
	if (user_choice == 446) { //if special input is provided, allow the user to access Supervisor Class
		cout << "Supervisord access granted!\n";
		cout << "Press 1 to see the result of the examination\n";
		checkInteger(supervisor_input);
		system("cls");

		//creating an object of class Supervisor and a pointer which is used to access its methods
		Supervisor Actual_Supervisor(employee_has_real_problem);
		Supervisor* access_methods = &Actual_Supervisor;
		access_methods->PrintTestOutcome();  //accessing the methods of class supervisor
		access_methods->LeadSupervisor();
		access_methods->SupervisorResponse();
	} 
	//printing another message
	cout << "Press any number to exit completely\n";
	int another_user_choice = 0;
	std::string SeniorPassword = "";
	checkInteger(another_user_choice);
	system("cls");

	//if the user input is this number, execute the code in this condition
	if (another_user_choice == 7143) {
		int attempts = 3;
		cout << "Welcome to the highest clearance section, enter the password to continue\n";
		//this do while loop asks for user input until the password is correct
		cout << "Enter the password whthout spaces: ' '\n";
		do {
			cin >> SeniorPassword;
			system("cls");
			if (SeniorPassword == "Pass_aye17")  //if password is correct, exit loop
				break;

			cout << "Error, wrong password, try again!\n";
			cout << "Attempts left: " << --attempts << "\n";
		} while (attempts > 0);
		//however, if the password is wrong, and there are no more attempts left, exit the program


		/*here the employee with the highest clearance will be able to see all the files
		because he/she has the highest clearance, however he/she is not allowed to share that data
		due to obvious confidential reasons */

		system("cls");
		cout << "Senior access granted!\n";
		cout << "Press 1 to see all the files stored in the program or any other number to exit: \n";
		int senior_choice = 0;
		checkInteger(senior_choice);

		if (senior_choice == 1) { //if senior choice is 1, execute this final block of code

			//creating a pointer to call the method of child class
			//the pointer points to a dinamically allocated object of the class, in heap memory
			AccessHighestClearance* accessItsMethod = new AccessHighestClearance;
			accessItsMethod->AccessHighestClearanceMethod();
			delete accessItsMethod; //always freeing up that memory
		}

		system("cls");
		//the end of the program for every user
		cout << "Thank you sir for using Dofa!";
	}

	return 0;
}
