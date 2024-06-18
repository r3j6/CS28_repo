#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string fname;
    string lname;
    int age;
    char gender;

    // Validation function for cellphone number
    bool isValidCellphoneNumber(const string &number) const {
        if (number.length() != 11) {
            return false;
        }

        if (number[0] != '0' || number[1] != '9') {
            return false;
        }

        for (size_t i = 0; i < number.length(); ++i) {
            if (!isdigit(number[i])) {
                return false;
            }
        }

        return true;
    }

public:
    string emailAdd;
    string cpNumber;

    // Constructor with first name and last name
    Person(const string &first = "", const string &last = "", int newage = 0, char g = 'M', const string &email = "", const string &cp = "")
        : fname(first), lname(last), age(newage), gender(g) {
        setEmailAdd(email);
        setCpNumber(cp);
    }

    // Accessor methods
    string getFname() const {
        return fname;
    }

    string getLname() const {
        return lname;
    }

    int getAge() const {
        return age;
    }

    char getGender() const {
        return gender;
    }

    // Mutator methods
    void setAge(int age) {
        if (age >= 0) {
            this->age = age;
        } else {
            cout << "\nInvalid age!!!" << endl;
        }
    }

    void setGender(char c) {
        if (c == 'M' || c == 'F') {
            gender = c;
        } else {
            cout << "\nInvalid gender!!!" << endl;
        }
    }

    void setEmailAdd(const string &email) {
        emailAdd = email;
    }

    void setCpNumber(const string &phone) {
        if (isValidCellphoneNumber(phone)) {
            cpNumber = phone;
        } else {
            cout << "Invalid phone number!!!" << endl;
        }
    }

    // View method
    void view() const {
        cout << "First Name: " << getFname() << endl;
        cout << "Last Name: " << getLname() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Email Address:" << emailAdd << endl;
        cout << "Cellphone Number: " << cpNumber << endl;
    }
};

#endif // PERSON_H

