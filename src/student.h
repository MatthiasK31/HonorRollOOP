#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class HonorRoll
{

private:
	string studentName = " ";
	int numberOfCourses = 0, sum = 0, avg = 0;
	vector<string> allCourseNames;
	vector<int> allTheGrades;


	bool hasDisciplineIssue = false;

public:
	//constructors
	HonorRoll();  //default constructor
	HonorRoll(string, int, int, int, vector<string>, vector<int>);



	string askForName();

	vector<string> askForCourse();
	vector<int> askForGrades();

	int calculateTotal();


	int numCourses();

	void printOutput();

	bool disiplineIssue();
	bool checkValidNumInput(string);
	bool checkValidGradeInput(string);

};