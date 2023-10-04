#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include "Header.h"

using std::cout;
using std::cin;


//This method stores to a map the test results of the employee and calculates the final results
void Employee::AddScore(double &user_choice, size_t &Question, std::string &CurrentMentalIllness) {
	system("cls");
	int results_input = 0;

	//creating a map in which we will store the score of each scale of the test
	static std::map<std::string, double> EachScaleScore{};
	static size_t funcExecuted90Times = 0;
	
	//this condition makes sure that only valid strings are stored to our map
	std::string wrongHostility = "Hostility ";
	if (CurrentMentalIllness != "none" && CurrentMentalIllness.find(wrongHostility))
		EachScaleScore[CurrentMentalIllness] += user_choice;

	/*here there is a wrong key that stores the value of user_choice next to it
	so we take that value and store it to the right key called "Hostility" */
	static bool execute_once = true;
	if (CurrentMentalIllness.find(wrongHostility) && execute_once == true) {
		EachScaleScore["Hostility"] += user_choice;
		execute_once = false;
	}

	//if the test finished, we will execute this condition
	
	//here we calculate the final score of each scale, by calculating the arithmetic mean
	double SomatizationScore = 0, DepressionScore = 0, ObssessiveScore = 0, PsychoticismScore = 0;
	double ParanoidScore = 0, HostilityScore = 0, InterpersonalScore = 0, AnxietyScore = 0, PhobicScore = 0;

	//storing each total score of our map to these variables
	SomatizationScore = EachScaleScore["Somatization"], ObssessiveScore = EachScaleScore["Obsessive"];
	InterpersonalScore = EachScaleScore["InterpersonalSensitivity"], DepressionScore = EachScaleScore["Depression"];
	AnxietyScore = EachScaleScore["Anxiety"], HostilityScore = EachScaleScore["Hostility"], PhobicScore = EachScaleScore["PhobicAnxiety"];
	ParanoidScore = EachScaleScore["ParanoidIdeation"], PsychoticismScore = EachScaleScore["Psychoticism"];

	//calculating the final score, using arithmetic mean to do that
	SomatizationScore /= 12, ObssessiveScore /= 10, InterpersonalScore /= 9, DepressionScore /= 14;
	AnxietyScore /= 10, HostilityScore /= 6, PhobicScore /= 7, ParanoidScore /= 6, PsychoticismScore /= 10;

	//if the function was called 90 times, it means that the test is finished and this condition will be executed
	if (funcExecuted90Times == 90) {
		//storing the final scores to this vector
		std::vector<double> FinalScores{ SomatizationScore, ObssessiveScore, InterpersonalScore,
		DepressionScore, AnxietyScore, HostilityScore, PhobicScore, ParanoidScore, PsychoticismScore
		};
		
		//End of Test(SCL-90)
		cout << "\nYou have completed the examination \n";
		cout << "\nPress 1 to see the results \n";
		isInputValid(results_input);

		//calling the next method because the test is now finished
		ResultsOfEmployee(FinalScores);
	}
	funcExecuted90Times++;
}

//defining this method called SclTest
void Employee::SCLTest() { //no parameters needed
	/*this function administers the psychological test to the user in order to establish an
	accurate diagnosis*/

	//variables that we need
	system("cls");
	double user_choice = 0;
	size_t Question = 1;
	bool fileOppened = true;
	std::string Somatization = "Somatization", ObsessiveCompulsiveD = "Obsessive", InterpersonalSensitivity = "Sensitivity";
	std::string Depression = "Depression", anxiety = "Anxiety", hostility = "Hostility", PhobicAnxiety = "PhobicAnxiety";
	std::string ParanoidIdeation = "ParanoidIdeation", Psychoticism = "Psychoticism", none = "none";
	std::vector<std::string> display_questions;
	std::vector<std::string> StoreMentalIlness;

	std::fstream IllnessesStoredHere;
	IllnessesStoredHere.open("Illness strings.txt");
	
	//if the file did not open, call the function 'HasFileOppened' to throw an exception
	if (!IllnessesStoredHere.is_open()) {
		fileOppened = false;
		hasFileOppened(fileOppened);  //throwing an exception if file did not open
	}
	else {
		std::string current_notepad_line = "";
		//storing each line of our notepad to the vector display_questions
		while (std::getline(IllnessesStoredHere, current_notepad_line)) {
			display_questions.push_back(current_notepad_line); 
		}
	}
	
	//using substrings to store the name of each illness to our vector display_questions
	for (std::string sentence : display_questions) {
	     char delimiter = '-';
		 if (sentence.find(delimiter) != std::string::npos) {
		 
		 // Calculate the length of the substring from delimiter position to the end
		 size_t delimiterPos = sentence.find(delimiter);
		 size_t length = sentence.length() - delimiterPos - 1;
		 std::string extractedIllness = sentence.substr(delimiterPos + 1, length);

		 //if our current string contains any additional spaces, we won't add it to our vector
		 if (extractedIllness.substr(0, 11) == "Depression ") {
			 //fixing our current string
			 if (extractedIllness.substr(0, 11) == "Depression ") extractedIllness = "Depression";
			 
		 }
		  StoreMentalIlness.push_back(extractedIllness);
		}
	}

	//correcting lines 45 an 69 of our vector to fix a bug, there were stored other words at these lines
	StoreMentalIlness[44] = "ParanoidIdeation";
	StoreMentalIlness[68] = "InterpersonalSensitivity";
    
	cout << "Choose an answer to every question from 0 to 4\n";
	cout << "\n0.Not at all  1.A little bit  2.Moderately  3.Quite a bit  4.Extremely\n";
	
	//Beginning of the test:
	cout << "FOR THE PAST WEEK, HOW MUCH WERE YOU BOTHERED BY :\n";
	for (size_t pos = 0; pos < 91; pos++) {
		cout << display_questions[pos] << "\n";
		//creating a copy of user_choice of type int so that we can check if input is valid
		int TestUserChoice = 0;
		TestUserChoice = static_cast<int> (user_choice);
		isInputValid(TestUserChoice);
		
		user_choice = TestUserChoice;
		//if input is too large or small, we will exit the program
		if (user_choice > 4) {
			system("cls");
			cout << "Error, number is to large, try again later!\n";
			exit(0);
		}
		else if (user_choice < 0) {
			system("cls");
			cout << "Error, number is too small, try again later\n";
			exit(0);
		}
		AddScore(user_choice, Question, StoreMentalIlness[pos]);  
		//calling this method to calculate the total score of each scale
	}

	system("cls");
}