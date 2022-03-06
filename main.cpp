// OverloadedExtractionOperatorStudent.cpp  Updated March 2022
// Demonstrates overloading operators:
//  extraction operator >>
//  insertion operator <<
//  equals operator ==
//
#include"Student.h"
#include<iostream>
using namespace std;

int main()
{
    cout << "Demonstrates extraction operator>> , insertion operator<< and operator== for a Student class.\n" << endl;

    Student s1( "John Stark", 56.4, -6.35);
    cout << "s1:\n" << s1; // invoke insertion operator<<

    Student s2; // default construction.
    cin >> s2;  // invokes the extraction operator>> to populate s2
    cout << "s2:\n" << s2;

    // Using the overloaded equals operator==
    // Change the values in s3 constructor one by one, and check that the == works correctly.
    Student s3("John Stark", 56.4, -6.35);

    cout << "s3:\n" << s3;

    if (s1 == s3)
        cout << "s1 == s3, is true." << endl;
    else
        cout << "s1 == s3, is false." << endl;

    cout << "Goodbye." << endl;

    // When we exit main(), the Student objects that were automatically created on the stack
    // go out of scope and will be automatically freed one-by-one from the stack.
    // Just before each student object is freed, its destructor will be automatically
    // called.
    // The job of the destructor is to free the dynamically allocated memory pointed to by
    // the 'location' field pointer.  Again, the Student class must be responsible for freeing up
    // any dynamically allocated memory.
}