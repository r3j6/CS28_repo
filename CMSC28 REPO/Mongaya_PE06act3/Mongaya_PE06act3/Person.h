#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person {
private:
    string fname;
    string lname;

public:
    // Constructor
    Person(const string &first, const string &last) : fname(first), lname(last) {}

    // Accessor methods
    string getFname() const {
        return fname;
    }

    string getLname() const {
        return lname;
    }
};

#endif

