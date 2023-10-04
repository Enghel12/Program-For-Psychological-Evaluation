#include<iostream>
#include<vector>
#include "Header.h"

using std::cout;
using std::cin;

void Employee::RequestHelp(std::vector<std::string> &IllnessesNames) {
	/*This function asks the user about the outcome of the Scl Test and then creates
	another notepad file which will contain the results of the examination*/
	int user_choice = 0;
	std::string employee_answer = "", last_additional_text = "";

	//creating a vector which will contain relevant information for a specialist to see
	std::vector<std::string> ContentForSupervisor;

	//printing a large message for the user
	cout << " Thank you for requesting help, what you type here will be saved and sent to\n"
		" an appropriate specialist, depending on the issue\n"
		" You will be asked 9 questions, each question referring to the score obtained on each\n"
		" Scl scale. If your score on a scale reflects that you might be suffering from\n"
		" something, type yes, if not, just type no. After this, the file with your responses\n"
		" will be sent to a specialist and you will soon be contacted, press 1 to begin or 2 to exit\n";
	    
	cout << " ";   //using this cout to alling the user input with the text from above
	isInputValid(user_choice);
	system("cls");
	cout << "\nSo tell us which symptomatic dimension score concluded that you might have a mental health condition\n\n";
	

	for (auto current_word : IllnessesNames) {
		cout << "Any issues on " << current_word << " scale?\n";
		
		//storing the employee's answer to vector ContentForSupervisor
		cin >> employee_answer;
		ContentForSupervisor.push_back("Employee answered with " + employee_answer + " on" + current_word + "Scale!");
		system("cls");
	}

	//making sure we clear the buffer every time
	cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
	cout << "\nIs there anything that you would like to add ?\n";
	getline(cin, last_additional_text);

	//inserting a string at the beginning of string : last_additional_text
	last_additional_text.insert(0, "Employee also stated that: \n");

	//creating the file for the specialist which will contain the employee's response
	std::ofstream EmployeeFile("HelpRequest.txt");
	if (!(EmployeeFile.is_open()))
		hasFileOppened(false);  //throwing an exception if the file did not open
	else {
		EmployeeFile << "Here is the request of the employee, it contains all the test scores\n";
		EmployeeFile << "And also a message from the employee: \n\n";

		//storing the answers of the employee from our vector to the notepad file
		for (auto sentence : ContentForSupervisor)
			EmployeeFile << sentence << "\n";

		cout << "\n";
		//storing the last message to the notepad
		EmployeeFile << last_additional_text << "\n";
	}
	EmployeeFile.close();


}