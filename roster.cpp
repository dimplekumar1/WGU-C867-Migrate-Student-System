#include "roster.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//default constructor
Roster::Roster() {}


//Destructor
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}



//To parse each set of data identified in the “studentData Table"
void Roster::parse(string parseData) {
	vector<string> dataParsed;
	size_t startSearch = 0;
	size_t endSearch = 0;

	for (int i = 0; i < numOfAttibutesInAdd; i++) {
		if (endSearch != string::npos) {
			endSearch = parseData.find(',', startSearch);
			dataParsed.push_back(parseData.substr(startSearch, endSearch - startSearch));
			startSearch = endSearch + 1;
		}
	}

	DegreeProgram degreeProgram = DegreeProgram::DEFAULT;

	if ((dataParsed.at(8).back()) == 'Y') {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if ((dataParsed.at(8).back()) == 'K') {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if ((dataParsed.at(8).back()) == 'E') {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(dataParsed.at(0), dataParsed.at(1), dataParsed.at(2), dataParsed.at(3), stoi(dataParsed.at(4)), stoi(dataParsed.at(5)), stoi(dataParsed.at(6)), stoi(dataParsed.at(7)), degreeProgram);
}



//To set the instance variables from "student.h" and updates the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++indexOfStudents] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeprogram);
}



//To remove students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found
void Roster::remove(string studentID) {
	int searchID = 0;
	while ((studentID != classRosterArray[searchID]->GetStudentID()) && searchID < sizeOfArray) {
		searchID = searchID + 1;
	}

	if (searchID < sizeOfArray) {
		cout << studentID << ": " << endl;
		sizeOfArray = sizeOfArray - 1;
		for (int j = searchID; j < sizeOfArray; j++) {
			Student* Transfer = classRosterArray[j];
			classRosterArray[j] = classRosterArray[j + 1];
			classRosterArray[j + 1] = Transfer;
		}
		cout << "The student with ID " << studentID << " was successfully removed." << endl;
	}
	else {
		cout << studentID << " again: " << endl;
		cout << "ERROR: The student with ID " << studentID << " was not found." << endl;
	}
}



//To print a complete tab-separated list of student data in the provided format
void Roster::printAll() {
	for (int i = 0; i < sizeOfArray; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->PrintStudentData();
		}
	}
}



//To correctly print a student’s average number of days in the three courses. The student is identified by the studentID parameter
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			if (studentID == classRosterArray[i]->GetStudentID()) {
				int averageDaysInCourse = (classRosterArray[i]->GetDaysInCourse()[0] +
					classRosterArray[i]->GetDaysInCourse()[1] +
					classRosterArray[i]->GetDaysInCourse()[2]) / 3;

				cout << "For Student ID ";
				cout << classRosterArray[i]->GetStudentID() << ": ";
				cout << averageDaysInCourse << " days" << endl;
			}
		}
	}
}



//To verify student email addresses and displays all invalid email addresses to the user. A valid email includes '@' and '.' and should not include a space.
void Roster::printInvalidEmails() {
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			if ((classRosterArray[i]->GetEmail().find('@') == string::npos) ||
				(classRosterArray[i]->GetEmail().find('.') == string::npos) ||
				(classRosterArray[i]->GetEmail().find(' ') != string::npos)) {

				cout << classRosterArray[i]->GetEmail() << endl;
			}
		}
	}
}



//To printout student information for a degree program specified by an enumerated type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << degreeProgramStrings[(int)degreeProgram] << ": " << endl;
	for (int i = 0; i < numStudents; i++) {
		if (degreeProgram == classRosterArray[i]->GetDegreeProgram()) {
			classRosterArray[i]->PrintStudentData();
		}
	}
}
