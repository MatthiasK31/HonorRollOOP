#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "student.h"


HonorRoll::HonorRoll() {}

HonorRoll::HonorRoll(string uName, int num, int allTotal, int mean, vector<string> theCourseNames, vector<int> theCourseGrades) {
	studentName = uName;
	numberOfCourses = num;
	sum = allTotal;
	avg = mean;
	allCourseNames = theCourseNames;
	allTheGrades = theCourseGrades;

}



string HonorRoll::askForName()
{
	//prompt user, clear cin, take input and return n
	cout << "What is your full name (first, last)?  " << endl;
	cin.clear();
	//cin.ignore(INT_MAX, '\n');
	getline(cin, studentName);
	return studentName;
}



vector<string> HonorRoll::askForCourse()
{
	//prompt user for input for as many times as the number of courses they entered
	cout << "\nPlease note that the maximum course name is 20 characters. \nAnything above that will be truncated to exactly 20." << endl;
	cout << "Please enter your course name twice if it prompts you to. " << endl;
	for (int i = 0; i < numberOfCourses; i++) {
		//ask for course num and take the entire line
		cout << "Course " << i + 1 << " name:  ";
		string courseName;
		//clear cin
		cin.clear();
		getline(cin, courseName);

		//if the course name is greater than 20 characters then continuously loop until it is less than 20
		if (courseName.length() > 20) {
			courseName = courseName.substr(0, 20);
		}
		else if (courseName.length() == 0) {
			while (true) {
				cout << "Please enter a course name greater than 0!  ";
				getline(cin, courseName);
				if (courseName.length() == 0) {
					continue;
				}
				else {
					break;
				}
			}
		}


		//append the checked and/or input to the vector
		allCourseNames.push_back(courseName);
	}

	//return vector
	return allCourseNames;
}

vector<int> HonorRoll::askForGrades()
{
	//define vector
	bool yesOrNo;

	cout << "\nFor each course, enter a grade from 0 to 120." << endl;

	//for loop to iterate through the courses and ask for the grade in each course
	for (int i = 0; i < numberOfCourses; i++) {
		//prompt user
		cout << "Enter your final " << allCourseNames.at(i) << " grade:\t";
		cin.clear();
		string grade = ""; getline(cin, grade);
		//while loop to ask user for a new grade while they are invalid
		yesOrNo = checkValidGradeInput(grade);

		//while the input is invalid keep iterating through the loop
		while (yesOrNo) {
			cout << "\tEnter a valid grade:\t";
			cin.clear();
			getline(cin, grade);
			yesOrNo = checkValidGradeInput(grade);
		}

		//append values to the vector
		double convert = stod(grade);
		allTheGrades.push_back(convert);
	}

	for (int i = 0; i < numberOfCourses; i++) {
		sum += allTheGrades.at(i);
	}
	avg = sum / numberOfCourses;

	return allTheGrades;
}

bool HonorRoll::checkValidGradeInput(string tester)
{
	//try-catch to validate input
	try {
		double temp = stod(tester);
		int num = stoi(tester); // error trap this with a try/catch block

		if (temp != num) {
			return true;
		}
		if (num > 120 || num < 0) {
			return true;
		}
	}
	catch (invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
}



int HonorRoll::numCourses()
{
	//declare variables
	string courses = "";
	bool yesOrNo;

	//prompt user and ask for input
	cout << "How many courses do you plan to take?\t";
	getline(cin, courses);
	yesOrNo = checkValidNumInput(courses);

	//while the input is invalid keep iterating through the loop
	while (yesOrNo) {
		cout << "\tEnter a valid course number:\t";
		getline(cin, courses);
		yesOrNo = checkValidNumInput(courses);
	}

	//convert the string into an int, then return it
	numberOfCourses = stoi(courses);
	return numberOfCourses;
}

bool HonorRoll::checkValidNumInput(string tester)
{
	//try-cathc to validate input
	try {
		double temp = stod(tester);
		int num = stoi(tester); // error trap this with a try/catch block

		if (temp != num) {
			return true;
		}
		if (num > 8 || num < 1) {
			return true;
		}
	}
	catch (invalid_argument& e) {
		//prompt user for valid input/continue loop
		return true;
	}
	return false;
}

void HonorRoll::printOutput()
{
	//formatting the output chart
	cout << "\n\nName: " << studentName << "\n" << endl;;
	cout << "Course:\t\t\t\tGrade" << endl;
	for (int i = 0; i < allTheGrades.size(); i++) {
		cout << allCourseNames.at(i) << "\t\t\t\t" << allTheGrades.at(i) << "\n";
	}
	cout << "\nYour final average across all " << numberOfCourses << " of your courses is " << avg << "." << endl;

	//displaying the disciplinary infraction
	cout << "\nDisciplinary Infraction: ";
	if (hasDisciplineIssue == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	hasDisciplineIssue = disiplineIssue();
	//determining honor roll
	if (avg >= 90 && numberOfCourses >= 5 && hasDisciplineIssue == false) {
		cout << "\nCongratulations " << studentName << "! You are eligible for honor roll!" << endl;
	}
	else {
		cout << "\nI'm sorry " << studentName << ", but you didn't qualify for honor roll." << endl;
	}
}

bool HonorRoll::disiplineIssue()
{
	//out of 100 numbers generated, if the random selected number is from 1 to 5, then return a true value
	srand(time(NULL));
	int percentage = rand() % 100 + 1;

	if (percentage >= 1 && percentage <= 5) {
		hasDisciplineIssue = true;
	}
	else {
		hasDisciplineIssue = false;
	}

	//return bool value
	return hasDisciplineIssue;
}