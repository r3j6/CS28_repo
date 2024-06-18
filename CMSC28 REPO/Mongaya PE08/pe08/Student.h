#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    string studentNum;

public:
    string course;
    string department;
    string college;

    // Constructor with Person and Student specific attributes
    Student(const string &first, const string &last, int newage, char g, const string &email, const string &cp, const string &snum, const string &course, const string &dept, const string &col)
        : Person(first, last, newage, g, email, cp), studentNum(snum), course(course), department(dept), college(col) {}

    // Accessor method for studentNum
    string getStudentNum() const {
        return studentNum;
    }

    // Mutator method for studentNum
    void setStudentNum(const string &num) {
        studentNum = num;
    }

    // View method
    void view() const {
        // Call the base class view method
        Person::view();
        // Output additional Student-specific information
        cout << "Student Number: " << getStudentNum() << endl;
        cout << "Course: " << course << endl;
        cout << "Department: " << department << endl;
        cout << "College: " << college << endl;
    }

    // Custom greeting method
    void greet() const {
        cout << "Hi " << getFname() << " " << getLname() << "! Welcome to UP Mindanao and congratulations! We are pleased to inform you that you are admitted in the " 
             << course << " program under the " << department << ", " << college 
             << ". Your Student number is " << getStudentNum() << "." << endl;
    }
};

#endif // STUDENT_H
