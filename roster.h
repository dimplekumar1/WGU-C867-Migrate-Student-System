#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {
private:
	//******data members******
	int sizeOfArray = 5;
	static const int numStudents = 5;
	static const int numOfAttibutesInAdd = 9;
	int indexOfStudents = -1;

	
public:

	//Creating an array of pointers, "classRosterArray", to hold the data provided in the “studentData Table”
	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };


	//******functions******

	//default constructor
	Roster();


	//Destructor
	~Roster();


	//To parse each set of data identified in the “studentData Table"
	void parse(string parseData);


	//To set the instance variables from "student.h" and updates the roster
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);


	//To remove students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found
	void remove(string studentID);


	//To print a complete tab-separated list of student data in the provided format
	void printAll();


	//To correctly print a student’s average number of days in the three courses. The student is identified by the studentID parameter
	void printAverageDaysInCourse(string studentID);


	//To verify student email addresses and displays all invalid email addresses to the user. A valid email includes '@' and '.' and should not include a space
	void printInvalidEmails();


	//To printout student information for a degree program specified by an enumerated type
	void printByDegreeProgram(DegreeProgram degreeProgram);

};


#endif



