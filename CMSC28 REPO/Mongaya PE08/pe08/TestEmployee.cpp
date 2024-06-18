#include <iostream>
#include "Person.h"
#include "Employees.h"

using namespace std;

int main() {
    string fname, lname, empNum, position, officeUnit, email, cpNumber;
    int age;
    char gender;
    float salary;

    // Display the header information
    cout << "Employees Record System" << endl;
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

    cout << "Input employee number: ";
    cin >> empNum;

    cin.ignore();

    cout << "Input position: ";
    getline(cin, position);

    cout << "Input Office or Unit: ";
    getline(cin, officeUnit);

    cout << "Input salary: ";
    cin >> salary;

    // Create Employee object
    Employees e(fname, lname, age, gender, email, cpNumber, empNum, position, officeUnit, salary);

    // Call all methods from Employees and Person classes
    cout << "===============================================\n\n";
    cout << "\nDisplaying Employee Information:" << endl;
    e.view();
    cout << "===============================================\n\n";
    e.greet();

    return 0;
}

