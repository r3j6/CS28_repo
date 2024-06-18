#include <iostream>
#include "Person.h"
#include "Student.h"

using namespace std;

int main() {
    string fname, lname, studentNum, course, department, college, email, cpNumber;
    int age;
    char gender;

    // Display the header information
    cout << "Student Record System" << endl;
    cout << "by: Renz Jaepril Mongaya\n";
    cout << "K-1L\n";
    cout << "===============================================\n\n";
    
    
    cout << "Input first name:";
    cin >> fname;

    cout << "Input last name:";
    cin >> lname;

    cout << "Input age: ";
    cin >> age;

    cout << "Input gender (M/F): ";
    cin >> gender;

    cout << "Input email address: ";
    cin >> email;

    cout << "Input cellphone number 11Digits (09*********): ";
    cin >> cpNumber;

    cout << "Input student number: ";
    cin >> studentNum;

    cin.ignore(); 

    cout << "Input course: ";
    getline(cin, course);

    cout << "Input department: ";
    getline(cin, department);

    cout << "Input college: ";
    getline(cin, college);

    // Create Student object
    Student s(fname, lname, age, gender, email, cpNumber, studentNum, course, department, college);

    // Call all methods from Student and Person classes
    cout << "===============================================\n\n";
    cout << "Displaying Student Information:" << endl;
    s.view();
    cout << "===============================================\n\n";
    s.greet();

    return 0;
}
