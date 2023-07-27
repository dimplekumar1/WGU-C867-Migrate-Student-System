#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
#include <string>
using namespace std;


class Student {

public:
	//******creating a variable to define the size of the array for the data member "numDaysInCourse" below******

	static const int numCourses = 3;

private:
	//******data members******

	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDaysInCourse[numCourses];
	DegreeProgram degreeProgram;


public:
	//******functions******

	//default constructor
	Student();


	//constructor with all of the input parameters provided in the table
	Student(string aStudentID, string aFirstName, string aLastName, string aEmail, int aAge, int aDaysInCourse[], DegreeProgram aDegreeProgram);


	//Destructor
	~Student();


	//mutator functions for each instance of data members
	void SetStudentID(string bStudentID);
	void SetFirstName(string bFirstName);
	void SetLastName(string bLastName);
	void SetEmail(string bEmail);
	void SetAge(int bAge);
	void SetDaysInCourse(int bDaysInCourse[]);
	void SetDegreeProgram(DegreeProgram bDegreeProgram);


	//accessor functions for each instance of data members
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	const int* GetDaysInCourse() const;
	DegreeProgram GetDegreeProgram() const;


	//accessor function to print student data
	void PrintStudentData();
};

#endif