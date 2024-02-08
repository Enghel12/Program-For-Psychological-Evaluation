#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include <memory>
#include <map>

extern bool employee_has_real_problem;
using std::cout;
using std::cin;

//declaration of my class Employee and its methods
class Employee {
protected: 
	/*using the access modifier protected to rely on encapsulationand making sure these
    methods cannot be accessed directly outside of our class*/
    
	//declaring the methods of class Employee
	void EmployeeInformation();
	void Questions(std::vector<std::string>& EmployeeInfo);
	void saveInformation(std::vector<std::string> &EmployeeReason, std::vector<std::string>& EmployeeInfo);
	void RequestHelp(std::vector<std::string> &IllnessesNames);
	void ResultsOfEmployee(std::vector<double> &FinalScores);
	void AddScore(double& user_choice, size_t& Question, std::string& CurrentMentalIllness);
	void SCLTest();
	void isInputValid(int &is_int);
	void hasFileOppened(bool hasOppened);
	void AddStringToVector(std::string& current_input, std::string current_message,
	                       std::vector<std::string>& EmployeeInfo);
	void AddIntToVector(int current_input, std::string ConsoleIntMessages,
		               std::vector<std::string>& EmployeeInfo);
	//all these methods of class Employee will be accessed by other methods of class Employee

};

//creating a child class and using it to access the parent class Employee
class AccessEmployee: public Employee {   
//using 'public' to state that the methods of parent class can be accessed by the child class
public:
	
	void AccessProtectedFunctions() {  //this function will access the methods of parent class
		EmployeeInformation();
		SCLTest();
		//end of the function of child class
	}

};

class Supervisor {
private:  //member of our class encapsulated
	bool is_employee_ok;
	int supervisor_input = 0;
	/*depending on the value of the global called employee_has_real_problem
	variable the method of this class will behave in two differnet ways*/
public:

	//constructor
	Supervisor(bool isEmployeeOk) {  //pasing the value of our global varable to that member
		is_employee_ok = isEmployeeOk;
	}

	//informing the supervisor about the outcome of the test by using methods down below
	std::string PrintTestOutcome() {
		if (is_employee_ok)  //as I said, the return of this function depends on the value of the global variable
			return "The decrease in the performance of the employee was not caused by a mental health condition\n";
		return "The decrease in the performance of the employee might have been caused by a mental health condition";
	}
	//this function informs the supervisor about what can be done, depending on the case
	std::string LeadSupervisor() {
		int exit = 0;
		std::string supervisor_last_input = "";
		if (is_employee_ok) {//if is_employee_ok = true, print this messages to console
			system("cls");
			cout << "Since the employee is ok, according to the company procedure \n\n";
			cout << "Here is what you need to do next: \n\n";
			cout << "The employee's drop in performance cannot be explained \n\n";
			cout << "by the psychological evaluation, this means that the problem might\n\n";
			cout << "not be a psychological one\n\n";
			cout << "It is recommended that you have a discussion one on one with the employee\n\n";
			cout << "And talk about what would be the real reason why he/she cannot perform as well as before\n\n";

			cout << "You have two options: You can either talk to the employee\n\n";
			cout << "Or ask for the help of another supervisor\n\n";
			cout << "1.Talk to the employee, 2.Pass the case to someone else\n\n";
			std::cin >> supervisor_input;  //taking user input

			//depending on the user input, one of these cases will be executed
			switch (supervisor_input) {
			case 1:
				system("cls");
				cout << "Alright, option was saved, you can talk to the employee\n";
				cout << "Your response has been saved!\n";
				cout << "Thank you for using Dofa, press anything to exit now\n";
				
				std::cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
				std::getline(cin, supervisor_last_input);
				for (auto i = 0; i < 1000; i++)
					cout << "Exitting Dofa....\n";
				break;

			case 2:
				system("cls");
				cout << "Alright, option was saved, the case has been passed!\n";
				cout << "Your response has been saved!\n";
				cout << "Thank you for using Dofa, press anything to exit now\n";
				
				std::cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
				std::getline(cin, supervisor_last_input);
				for (auto i = 0; i < 1000; i++)
					cout << "Exitting Dofa....\n";
				break;

			default:  //if input is wrong, exit the program
				cout << "Wrong input... exiting the program\n";
				std::exit(0);
			}
			return "";
		}
		if (!is_employee_ok) {  //if this variable is false, print these messages to the user
			system("cls");
			cout << "Due to confidential reasons, we cannot share more about the employee's situation\n\n";
			cout << "However only one thing is allowed to be said, the employee is suffering from something real\n\n";
			cout << "This is why there was a drop in performance, now the employee was given the option\n\n";
			cout << "To ask for help, so that he/she can get back on track\n\n";
			cout << "Thank you for using dofa press 1 to exit\n\n";
			std::cin >> exit; //here we exit the program

			return ""; //returing an empty string at the end
		}
	}

	//last method of our class, its purpose is to create a file with the response of the superviros
	void SupervisorResponse() {
		std::ofstream SupervisorFile("SupervisorResponse.txt");
		if (!(SupervisorFile.is_open())) {  //if file did not open, exit program
			cout << "Error, cannot open file!";
			exit(0);
		}
		else { //storing the choice of the supervisor to our file
			SupervisorFile << "The supervisor stated that: \n";
			if (supervisor_input == 1)
				SupervisorFile << "He/She will talk to the employee\n";
			else if (supervisor_input == 2)
				SupervisorFile << "The case will be passed to someone else\n";
			else
				SupervisorFile << "He/She did not choose a valid option\n";
		}
		SupervisorFile.close();
	}

};

class HighestClearance {
private: //encapsulate everything in this class

	void PrintEverything() { //this function prints the content of all the files
		//storing the name of the files to this vector
		std::vector<std::string> AllFileNames{ "EmployeePrivateInformation.txt",
		"Conclusions.txt", "HelpRequest.txt", "SupervisorResponse.txt"
		};

		system("cls");
		//storing the content of each file to string CurrentFileContent
		for (const std::string& CurrentFileContent : AllFileNames) {
			//using an ifstream to open all the files one by one
			std::ifstream OpenCurrentFile(CurrentFileContent); 

			if (OpenCurrentFile.is_open()) {
				std::string line = "";
				while (getline(OpenCurrentFile, line)) //printing the content of each file
					cout << line << "\n";
			}
			OpenCurrentFile.close();
			cout << "\n\n";
		}

		cout << "\nPress anything to continue\n";
		std::string anything = "";
		cin >> anything;

	}
	void MakeReview() {
		cout << "Enter here the number of stars that you give to it\n";
		std::string stars = "", feedback = "";
		int senior_choice = 0;
		cin >> stars;

		system("cls");
		cout << "Thank you sir!";
		cout << "Before you leave would you like to give us a detailed feedback ? \n";
		cout << "Press 1 for Yes, 2 For no\n";
		cin >> senior_choice;
		if (senior_choice == 1) {
			cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
			cout << "\nEnter feedback: \n";
			std::getline(cin, feedback);
		}
		//storing the senior review to a file(last file of Dofa)
		std::ofstream LastFile("Senior's opinion.txt");
		if (LastFile.is_open()) { //if my file opened
			//writing to the file
			LastFile << feedback;
		}
		LastFile.close();
	}

	//declaring the child class as a friend so that it can access it's methods
	friend class AccessHighestClearance; 
};
//creating another child class to access the methods of its parent class which are encapsulated
class AccessHighestClearance:public HighestClearance {
public:

	void AccessHighestClearanceMethod() {  //this function accesses the methods of HighestClearance class
		//creating an unique pointer to access the methods of our child class
		std::unique_ptr<HighestClearance> accessMethod = std::make_unique<HighestClearance>();
		accessMethod->PrintEverything(); //accesing the first method of class

		system("cls");
		cout << "Would you like to rate our app, it would help the it departament\n";
		cout << "Press 1 for yes, or any other number for no\n";
		int senior_rate = 0;
		cin >> senior_rate;
		if (senior_rate == 1)  //if user input is one, access the method make review
			accessMethod->MakeReview();
		
	}
};