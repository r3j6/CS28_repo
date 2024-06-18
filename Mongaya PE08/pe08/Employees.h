#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "Person.h"
#include <iomanip>

class Employees : public Person {
private:
    string empNum;

public:
    string position;
    string officeUnit;
    float salary;

    // Constructor with Person and Employees specific attributes
    Employees(const string &first, const string &last, int age, char g, const string &email, const string &cp, const string &empNum, const string &pos, const string &OU, float sal)
        : Person(first, last, age, g, email, cp), empNum(empNum), position(pos), officeUnit(OU), salary(sal) {}

    // Accessor methods for Employees-specific attributes
    string getEmpNum() const {
        return empNum;
    }

    string getPosition() const {
        return position;
    }

    string getOfficeUnit() const {
        return officeUnit;
    }

    float getSalary() const {
        return salary;
    }

    // Mutator methods for Employees-specific attributes
    void setSalary(float sal) {
        if (sal >= 0) {
            salary = sal;
        } else {
            cout << "Invalid salary" << endl;
        }
    }

    // View method
    void view() const {
        // Call the base class view method
        Person::view();
        // Output additional Employees-specific information
        cout << "Employee Number: " << getEmpNum() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Office or Unit: " << getOfficeUnit() << endl;
        cout << "Salary: " << fixed << setprecision(2) << getSalary() << endl;
    }

    // Greeting method
    void greet() const {
        cout << "Hi " << getFname() << " " << getLname() << "! Welcome to our Company! We are pleased to inform you that you are assigned as the " 
             << getPosition() << " under the " << getOfficeUnit() << ". Your employee number is " << getEmpNum() << ". Your salary for this month is " 
             << fixed << setprecision(2) << getSalary() << "." << endl;
    }
};

#endif // EMPLOYEES_H
