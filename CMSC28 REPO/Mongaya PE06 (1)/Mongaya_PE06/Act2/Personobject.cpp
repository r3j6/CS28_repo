#include <iostream>
#include "Person.h" // Add Person.h as a library to this program
#include "Grade.h"  // Add Grades.h as a library to this program
using namespace std;

int main() {
    int a;
    char g;
    int grade;
    string subject; // Changed from char to string

    cout << "Creating the 1st Person object (p) using the 1st Constructor" << endl;
    Person p;

    cout << "\nInput age: ";
    cin >> a;
    p.setage(a);

    cout << "Input gender: ";
    cin >> g;
    p.setgender(g);

    // Using Grades class
    cout << "\nInput Grade: ";
    cin >> grade;

    // Clearing the input buffer before reading the subject
    cin.ignore();
    
    cout << "Input Subject: ";
    getline(cin, subject); // Reading the subject as a string

    cout << "Age = " << p.getage() << endl;
    cout << "Gender = " << p.getgender() << endl;

    Grades personGrades(grade, subject);

    // Print the person's grade and subject
    cout << "Person's Grade: " << personGrades.getgrade() << endl;
    cout << "Person's Subject: " << personGrades.getsubject() << endl;

    return 0;
}

