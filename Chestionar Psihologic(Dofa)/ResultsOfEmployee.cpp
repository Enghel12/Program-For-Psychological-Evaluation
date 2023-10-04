#include<iostream>
#include<vector>
#include "Header.h"

using std::cout;
using std::cin;

extern bool employee_has_real_problem;

//definition of this method
void Employee::ResultsOfEmployee(std::vector<double> &FinalScores) {
	/*This method prints the conclusions after the Scl test and it informs the employee 
	whether he/she is suffering from a real condition or not */

	//if false_alarm is true, it means that the employee does not suffer from any condition
	bool false_alarm = true;
	size_t pos = 0;
	int user_choice = 0, request_help = 0, exit_program = 0;
	std::string FinalConclusion = "", line = "";

	//using this vectors to store the final conclusions which will be printed to the user
	std::vector<std::string> PrintRealIssues;
	std::vector<std::string> PrintIfNoIssues;

	//using the strings of this vector to form the conclusions in the for loop down below
	std::vector<std::string> IllnessesNames{ " Somatization ", " ObsessiveCompulsiveDisorder ",
	 " Interpersonal Sensitivity ", " Depression ", " Anxiety ", " Hostility ", " Phobic Anxiety ",
	 " Paranoid Ideation ", " Psychoticism "
	};
	
	//moving each score to currentScaleScore and comparing it to 1.5
	for (auto currentScaleScore : FinalScores) {
		
		//storing the conclusion of each scale in these conditions
		if (currentScaleScore > 1.5) {
			false_alarm = false;
			//just storing to this vector 4 strings concatenated which will be printed to console
			PrintRealIssues.push_back(IllnessesNames[pos] + ": According to the results obtained on the" + 
			  IllnessesNames[pos] + "dimension, you might be suffering from a real mental health condition\n\n");

		}
		else if (currentScaleScore < 1.5) {
			//doing the same for this vector but with 3 strings
			PrintIfNoIssues.push_back(IllnessesNames[pos] + " No real issues on the " + IllnessesNames[pos] + "scale\n\n");
			//Printing again the conclusion but for the second vector
			
		}
	 pos++; //updating the position when traversing the vector
	}

	if (false_alarm)
		FinalConclusion += "FINAL.CONCLUSION: you are not suffering from any mental health condition";
	else
		FinalConclusion += "FINAL CONCLUSION: YOU MIGHT SUFFER FROM A MENTAL HEALTH CONDITION AND WE HIGHLY RECOMMEND YOU TO SEEK PROFESSIONAL HELP AND TO TALK TO YOUR SUPERVISOR!\n";

    //creating another notepad file called conclusions
	std::ofstream File("Conclusions.txt");
	if (!(File.is_open())) {
		hasFileOppened(false);
	}
	else {  //here we store the conclusions(strings of the two vectors) to the notepad
		File << FinalConclusion << "\n";
		for (auto currentString : PrintRealIssues)
			File << currentString << "\n";

		for(auto currentString: PrintIfNoIssues)
			File << currentString << "\n";
	}
	File.close();

	//creating a file ifstream to read the content of our notepad and print it to console
	std::ifstream AnotherFile("Conclusions.txt");
	if (!(AnotherFile.is_open())) {
		hasFileOppened(false);
	}
	else {//using getline to move each line of our notepad to string line and then printing it
		while (getline(AnotherFile, line))
			cout << line << "\n";
	}
	AnotherFile.close();


	cout << "Press 1 to continue ";
	isInputValid(user_choice);
	system("cls");

	//if the employee might be suffering from something, execute this block of code
	if (!false_alarm) {
		cout << "Do you wish to request the help from a specialist right now ? \n";
		cout << "1.Yes 2.No\n";
		
		isInputValid(request_help);  //checking to see if input is valid
		if (request_help == 1)
			RequestHelp(IllnessesNames);  //calling another method if input = 1
	}
    
	//if the employee is suffering from something real, this boolean becomes true
	employee_has_real_problem = false_alarm;
}