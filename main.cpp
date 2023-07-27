#include "roster.h"
#include <iostream>
#include <string>
using namespace std;


int main() {

	//the course title, the programming language used, my WGU student ID, and my name.
	cout << "Course: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: 010533793" << endl;
	cout << "Student Name: Dimple Kumar" << endl;
	cout << endl;



	//student data input
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	  "A5,Dimple,Kumar,dkuma30@wgu.edu,24,34,28,23,SOFTWARE" };



	const int numStudents = 5;

	

	//creating an instance of "Roster" class
	Roster classRoster;



	//parse each set of the above student data input
	for (int i = 0; i < numStudents; i++) {
		classRoster.Roster::parse(studentData[i]);
	}



	//print all student data
	cout << "Displaying the information of all students: " << endl;
	classRoster.printAll();
	cout << endl;



	//print all invalid email addresses
	cout << "Displaying all invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;



	//loop through classRosterArray and for each element and print average number of days in three courses
	cout << "Displaying the average number of days in three courses: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	cout << endl;



	//print student information in a specific degree program
	cout << "Displaying the information of students in degree program ";
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;



	//remove a specific student from the list
	cout << "Removing student with ID ";
	classRoster.remove("A3");
	cout << endl;



	//print the updated student data after a student was removed from the list
	cout << "Displaying the updated list of students with their information: " << endl;
	classRoster.printAll();
	cout << endl;



	//remove the same student again from the list
	cout << "Removing student with ID ";
	classRoster.remove("A3");
	cout << endl;

	
	//ending the program with the below message
	cout << "DONE!" << endl;
	cout << "NOW IMPLEMENTING DESTRUCTOR." << endl;

	return 0;
}