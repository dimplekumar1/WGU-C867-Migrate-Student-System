#ifndef DEGREE_H
#define DEGREE_H

#include <iostream>
#include <string>
using namespace std;

//defining an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.
enum class DegreeProgram { DEFAULT, SECURITY, NETWORK, SOFTWARE };


//array of strings to use with the above enum class 
static const string degreeProgramStrings[] = { "DEFAULT", "SECURITY", "NETWORK", "SOFTWARE" };

#endif