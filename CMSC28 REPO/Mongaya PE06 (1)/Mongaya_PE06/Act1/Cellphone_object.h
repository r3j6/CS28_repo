#include <iostream>
#include <string>
using namespace std;

class Cellphone {
private: 
    string brand;
    int weight;
    int storage;

// Constructor
public: 
    Cellphone(string cpbrand, int cpweight, float cpstorage) {
        brand = cpbrand;
        weight = cpweight;
        storage = cpstorage;
    }

    void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Weight (in grams): " << weight << endl;
        cout << "Storage (in GB): " << storage << endl;
    }
};
