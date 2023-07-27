#include "student.h"
#include <iostream>
#include <string>
using namespace std;



//defining the default constructor
Student::Student() {
	studentID = "No ID";
	firstName = "No First Name";
	lastName = "No Last Name";
	email = "No Email";
	age = 0;
	for (int i = 0; i < numCourses; i++) {
		numDaysInCourse[i] = 0;
	}
	degreeProgram = DegreeProgram::DEFAULT;
}



//defining constructor with input parameters provided in the table
Student::Student(string aStudentID, string aFirstName, string aLastName, string aEmail, int aAge, int aDaysInCourse[], DegreeProgram aDegreeProgram) {
	this->studentID = aStudentID;
	this->firstName = aFirstName;
	this->lastName = aLastName;
	this->email = aEmail;
	this->age = aAge;
	for (int i = 0; i < numCourses; i++) {
		this->numDaysInCourse[i] = aDaysInCourse[i];
	}
	this->degreeProgram = aDegreeProgram;
}



//defining Destructor
Student::~Student() {}



//defining mutator functions for each instance of data members
void Student::SetStudentID(string bStudentID) {
	this->studentID = bStudentID;
}

void Student::SetFirstName(string bFirstName) {
	this->firstName = bFirstName;
}

void Student::SetLastName(string bLastName) {
	this->lastName = bLastName;
}

void Student::SetEmail(string bEmail) {
	this->email = bEmail;
}

void Student::SetAge(int bAge) {
	this->age = bAge;
}

void Student::SetDaysInCourse(int bDaysInCourse[]) {
	for (int i = 0; i < numCourses; i++) {
		this->numDaysInCourse[i] = bDaysInCourse[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram bDegreeProgram) {
	this->degreeProgram = bDegreeProgram;
}



//defining accessor functions for each instance of data members
string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

const int* Student::GetDaysInCourse() const {
	return numDaysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}



//defining accessor function to print student data
void Student::PrintStudentData() {
	cout << studentID << '\t' << " ";
	cout << firstName << '\t' << " ";
	cout << lastName << '\t' << " ";
	cout << email << '\t' << " ";
	cout << age << '\t' << " ";
	cout << "{ ";
	for (int i = 0; i < numCourses; i++) {
		if (i != numCourses - 1) {
			cout << numDaysInCourse[i] << ", ";
		}
		else {
			cout << numDaysInCourse[i];
		}
	}
	cout << " }" << '\t' << " ";
	cout << degreeProgramStrings[(int)degreeProgram] << '\t' << " ";
	cout << endl;
}


