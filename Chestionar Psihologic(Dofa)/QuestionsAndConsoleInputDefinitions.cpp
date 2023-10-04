#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <fstream>
#include "Header.h" 

using std::cout;
using std::cin;
using std::string;
using std::stringstream;

//This function prints messages to user and stores that a string to the vector EmployeeInfo
void Employee::AddStringToVector(std::string& current_input, std::string current_message,
	std::vector<std::string>& EmployeeInfo) {

	system("cls");
	string user_input = "";
	cout << current_message;
	cin >> user_input;
	current_input += user_input;
	EmployeeInfo.push_back(current_input);  //storing the string to the vector

}

//This function prints messages to user and stores an int to the vector EmployeeInfo
void Employee::AddIntToVector(int current_input, std::string ConsoleIntMessages,
	std::vector<std::string>& EmployeeInfo) {

	system("cls");
	cout << ConsoleIntMessages;
	isInputValid(current_input);
	stringstream ss;
	ss.str(std::to_string(current_input));
	EmployeeInfo.push_back(ss.str());  //storing the input to the vector
	ss.clear(); //clearing the stringstream


}

void Employee::Questions(std::vector<std::string>& EmployeeInfo) {
	/*This function asks the user about personal informationand stores that info to a
	vector of strings*/

	//variables needed
	int Age = 0, SocialSecurityNum = 0, repeatLoop = 0;
	string Address = "Address: ", Email = "Email: ", MaritalStatus = "Marital Status: ";
	string Name = "Name: ";
	bool user_finished = false;

	//Name of vector refers to messages that are printed when user input is a string
	std::vector<string> ConsoleStringMessages{
	  "Enter your full name without space: (ex: GeorgeLawren) \n",
	  "Enter your home adress without space: (ex: LiviuRebreanuNr8) \n",
	  "Enter your email: \n","Are you currently married ? \n"
	};
	//Name of vector refers to messages that are printed when user input is an integer
	std::vector<string> ConsoleIntMessages{
	  "Enter your age: \n", "Enter your social security number: \n"
	};

	system("cls");
	do {

		EmployeeInfo.clear();  //emptying the vector after each repetition of the loop

		//calling the functions to ask the user the questions and store the answers to EmployeeInfo
		AddStringToVector(Name, ConsoleStringMessages[0], EmployeeInfo);
		AddIntToVector(Age, ConsoleIntMessages[0], EmployeeInfo);
		AddIntToVector(SocialSecurityNum, ConsoleIntMessages[1], EmployeeInfo);
		AddStringToVector(Address, ConsoleStringMessages[1], EmployeeInfo);
		AddStringToVector(Email, ConsoleStringMessages[2], EmployeeInfo);
		AddStringToVector(MaritalStatus, ConsoleStringMessages[3], EmployeeInfo);
		//End of the questions


		//Printing the user input to the console
		system("cls");
		for (auto i = 0; i < EmployeeInfo.size(); i++) {
			/*if i is at a position in vector where a number is stored, insert in front
			  of that number the words Age, or Social Security Number to look better like
			  this: Age: num1, Social Security Number: num2
			*/
			if (i == 1) EmployeeInfo[i] = "Age: " + EmployeeInfo[i];
			if (i == 2) EmployeeInfo[i] = "Social Security Number: " + EmployeeInfo[i];

			cout << EmployeeInfo[i] << "\n";
		}
		cout << "\nIs the information correct this time ? 1.Yes  2.No \n";
		cout << "\nIf you type 2 or any different number than 1\n";
		cout << "\nYou will have to go through the questions again\n";
		isInputValid(repeatLoop);

		if (repeatLoop == 1) user_finished = true;  //exiting the loop
		system("cls");

	} while (!user_finished);  //repeat the loop while user is not finished

}
