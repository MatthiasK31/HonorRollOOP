#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

int main() {
	string name = " ";
	int courses = 0, total = 0, average = 0;
	vector<string> allTheCourses;
	vector<int> everyGrade;

	HonorRoll studentOne(name, courses, total, average, allTheCourses, everyGrade);

	cout << "Welcome to the Honor Roll Determiner!\n" << endl;
	studentOne.askForName();

	cout << "\nNext, enter the number of courses you plan to take.\nThis must be between 1 and 8 inclusively." << endl;
	studentOne.numCourses();

	//call method for a for loop that asks for all of the courses the user takes
	studentOne.askForCourse();

	//call method for a for loop that asks for all the course grades
	studentOne.askForGrades();

	//print output
	studentOne.printOutput();


}