// Student.cpp  Updated March 2022
// Implementation of the Student class
// Demonstrates overloading operators:
//  extraction operator >>
//  insertion operator <<
//  equals operator ==
//
#include"Student.h"
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

Student::Student() {    // default constructor
    this->name = "John Doe";        // member access operator "->"
    location = new double[2];       // dynamic memory allocation
    location[0] = 0.0;  // latitude
    location[1] = 0.0;  // longitude
}

Student::Student(string name, double latitude, double longitude) {
    this->name = name;
    location = new double[2];  // latitude and longitude values
    location[0] = latitude;
    location[1] = longitude;
}

// Destructor to free up the location array
// This is called when a student object is deleted or goes out of scope.
// If we dont do this, then the dynamically allocated location array
// will not be freed, causing a memory leak.
//
Student::~Student()
{
    delete[] location;
}

// Overloading of the equality operator==
//
int Student::operator == (Student& otherStudent)
{
    // compare this student's name with other student's name
    if (this->name != otherStudent.name)
        return 0;   // false

    // compare the locations
    // As latitude and longitude are of type double, we must be careful when comparing them
    // as looking for exact matches is problematic due to rounding erors.
    //
    // This is not an issue with int values, as exact matches are possible

    double epsilon = 0.0000001; // closeness value.
    // if the difference between the two values is <= epsilon,
    // then we are accepting that these two values are equal.
    if (fabs(location[0] - otherStudent.location[0]) >= epsilon)
        return 0;

    if (fabs(location[1] - otherStudent.location[1]) >= epsilon)
        return 0;

    return 1;   // True. They are the same.
}

// Overloaded insertion operator<< is defined as a global function.
// ( so, no "Student::" qualifier is needed in front as it is not a member function of Student )
//
//  Usage:                   cout << s1;
//
ostream& operator<< (ostream& os, const Student& student)
{
    os << "Student details ( output by insertion operator<< )" << endl;
    os << "Name: " << student.name << endl;
    os << "Latitude: " << student.location[0] << endl;
    os << "Longitude: " << student.location[1] << endl << endl;
    return os;
}

// Extraction operator>> will read from cin and populate an existing Student class.
// "Student::" is not used as a qualifier here because operator>>
// is not a member function of Student, it is a global function.
// In the Student class, it is declared as a "friend" of the Student class
// so that it can directly access the private member data (fields) of the Student object.
//
// No validation is shown in this sample for simplicity.
//
// Usage:                    cin >> s1;
//
istream& operator>> (istream& is, Student& student)
{
    cout << "Enter student details ( this uses the overloaded extraction operator>> )" << endl;
    cout << "Enter name: ";
    getline(is, student.name); // needed to read whole line (including spaces).
    //is >> student.name;      // only works if there are no spaces in the inputted string.
    cout << "Enter latitude: ";
    is >> student.location[0];
    cout << "Enter longitude: ";
    is >> student.location[1];
    cout << endl;

    return is;
}