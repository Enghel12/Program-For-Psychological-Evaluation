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

/*Using the special syntax : "method_type ClassName:: method_name" to define all the methods of
class Employee, inside this cpp file, example : void Employee::RequestHelp()
*/

//Defining the method called EmployeeInfo that uses other two methods
void Employee::EmployeeInformation() {

	/*This function prompts the user to share information regarding himself / herself
	and asks for the user's consent*/

	//declaring and defining variables that we need within this method
	int consent = 0, begin = 0, Continue = 0;
	string anyKey = "";
	std::vector<string> EmployeeReason;
	std::vector<string> EmployeeInfo{};

	//leaving a message in this string to describe the use of the string
	string ReasonForBeingHere = "In this string the employee will describe why he/she is here\n";
	ReasonForBeingHere.erase(ReasonForBeingHere.begin(), ReasonForBeingHere.end());
	//clearing the string to make it ready for user input

	//There are the first messages displayed in the program that guide the user
	cout << "\nWelcome to DOFA and thank you for using our software \n"
		"\nBefore the examination begins, we need your consent\n"
		"\nBy agreeing you will be required to share with us personal data about yourself\n"
		"\nHowever this is all confidential, your data will not be shared with other contacts\n";

	cout << "\nHOWEVER DEPENDING ON YOUR SUPERVISOR, HE/SHE MIGHT BE ABLE TO SEE SOME OF THE RESULTS!\n";
	cout << "\n1.I agree with the terms and conditions  2.I do not agree and wish to exit the program\n";

	isInputValid(consent); //taking user input, storing in to consent and checking the input
	system("cls");

	/*If the user gives his consent the program will ask the user for his personal information
	If the choice of the user is 2 or a different number, the program will shut down*/

	/*using a switch to implement thatand variable consent to determine which case will
	be executed*/
	switch (consent)
	{
	case 1:
		cout << "Press 1 to begin:\n";
		isInputValid(begin);  //checking to see if input is valid
		break;

	case 2:
		for (auto i = 0; i < 10000; i++)  //displaying a message 10000 times
			cout << "Shutting down\n";
		system("cls");
		exit(0);  //then exiting the program

	default:
		cout << "\nWrong number choice, exiting the program..\n";
		exit(0);
	}

	cout << "\nBefore we begin, enter the reason why you are here and why do you need to go through DOFA\n";
	
	//ignoring all the remaining characters from the previous input so that we can use again getline
	cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');//clearing the buffer to ensure we can input again to a new string
	getline(cin, ReasonForBeingHere);
	system("cls");

	/*moving the content of string ReasonForBHere to a stringstream which is a special stream
	that can be used for both input and output*/
	stringstream reason;
	reason.str(ReasonForBeingHere);

	/*converting the stringstream to a stringand storing the same input of the employee to
	the vector called employeeReason*/
	EmployeeReason.push_back(reason.str());
	ReasonForBeingHere.erase(ReasonForBeingHere.begin(), ReasonForBeingHere.end());
	//emptying the string manually

	//accessing a protected method of class Employee
	cout << "Press 1 to continue: \n";
	isInputValid(Continue);
	if (Continue != 1) {
		cout << "Wrong number, try again later..\n";
		exit(0);
	}

	Questions(EmployeeInfo);

	system("cls");

	//Displaying the next set of messages
	cout << "\nAll the information has been saved successfully!\n"
		"\nNow you will begin a test/examination which will ask you a wide array of questions\n"
		"\nThe purpose of this test is to provide you with an accurate diagnosis regarding your mental state\n"
		"\nYou will receive the results almost instantly \n"
		"\nAfter the examination you will learn whether you might suffer from a real mental ilness or it's just a false alarm\n";

	cout << "\nPlease answer truthfully to all the questions for an accurate examination\n"
		"\nAlso please take into consideration that if the examination shows the possibility of a real issue(possible mental ilness)\n"
		"\nyou should definitely seek professional help, and you will also be provided with two links which you can use \n"
		"\nTo receive the help that you need \n"
		"\nEnter any key to begin the examination: \n";

	cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
	getline(cin, anyKey);
	system("cls");

	//accessing another method of our class Employee
	saveInformation(EmployeeReason, EmployeeInfo);
	system("cls");
}