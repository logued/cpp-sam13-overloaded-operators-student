#ifndef SAM13_OVERLOADED_OPERATORS_STUDENT_STUDENT_H
#define SAM13_OVERLOADED_OPERATORS_STUDENT_STUDENT_H

// Student header file                        Updated March 2022
// Demonstrates overloading operators:
//  extraction operator >>
//  insertion operator <<
//  equals operator ==

#include<iostream>
#include<string>

class Student               // Implementation is in student.cpp
{
private:
    std::string name;
    double* location;   // a pointer member, which will point to dynamic memory
                        // Once a pointer member is present, we must implement the destructor

public:
    Student();
    Student(std::string name, double latitude, double longitude);

    ~Student();  // destructor: is called automatically when object goes out of scope or is deleted

    int operator == (const Student& otherStudent);  // Overloaded "operator=="

    // "friend" declarations:
    // We declare the insertion and extraction operators ( << and >> )
    // as 'friend'.  These operators ( << and >> ) are not defined with the "Student::" qualifier
    // in the Student.cpp file, thus making them global operator functions
    // (as opposed to member functions of Student class).
    // If we declare them as 'friends', then the code in the friend functions can
    // directly access the fields (member data) of a Student class.
    //
    friend std::ostream& operator<< (std::ostream& out, const Student& student);
    friend std::istream& operator>> (std::istream& in, Student& student);
};


#endif //SAM13_OVERLOADED_OPERATORS_STUDENT_STUDENT_H
