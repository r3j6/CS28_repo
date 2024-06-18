#include <iostream>
using namespace std;

//Program description
void progdescription() {
    cout << "Program that finds the highest and lowest of three numbers and calculates their difference." << endl;
    cout << "By: Renz Jaepril G. Mongaya" << endl;
    cout << "04/28/2024" << endl;
    cout << "CMSC 28 K-1L" << endl;
    cout << endl;
}

// Read input data
void readdata(float &x, float &y, float &z ){
	cout << "Input Three Numbers"<< endl;
	cin >> x >> y >> z;
}

// Find Largest value
float getlarge(float x, float y, float z) {
    float temp = x, largest = x;
    if (y > temp) {
        temp = y;
        largest = y;
    }
    if (z > temp) {
        largest = z;
    }
    return largest;
}

// Find Smallest value
float getsmall(float x, float y, float z) {
    float temp = x, smallest = x;
    if (y < temp) {
        temp = y;
        smallest = y;
    }
    if (z < temp) {
        smallest = z;
    }
    return smallest;
}
//Show result
void showdata(float x, float y, float z, float largeval, float smallval, float diff) {
    cout << "Input numbers: " << x << ", " << y << ", " << z << endl;
    cout << "Highest value: " << largeval << endl;
    cout << "Smallest value: " << smallval << endl;
    cout << "Difference of highest value and smallest value:" << diff << endl;
} 

int main() {
    // Variable declarations
    float x, y, z, smallval, largeval, diff;

    // Display program description
    progdescription();

    // Ask for input
    readdata(x, y, z);

    // Get the smallest and largest values
    smallval = getsmall(x, y, z);
    largeval = getlarge(x, y, z);

    // Calculate the difference
    diff = largeval - smallval;

    // Display data
    showdata(x, y, z, largeval, smallval, diff);

    return 0;
}


