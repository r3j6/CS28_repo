#include <iostream>
#include <string>
using namespace std;

class Grades {
private:
    int grade;
    string subject; // Changed from char to string for representing subjects

public:
    // Constructor
    Grades(int G, string s) : grade(G), subject(s) {}

    void setgrade(int G) {
        if (G < 0 || G > 100) { // Check if the grade is within a valid range
            cout << "Invalid grade!!!" << endl;
        } else {
            grade = G;
        }
    }

    int getgrade() {
        return grade;
    }

    void setsubject(string s) { // Changed parameter type from char to string
        subject = s;
    }

    string getsubject() {
        return subject;
    }

    void view() {
        cout << "Grade is = " << grade << endl;
        cout << "Subject is = " << subject << endl;
    }
};

