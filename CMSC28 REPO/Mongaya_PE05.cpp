#include <iostream>
using namespace std;

// Program description
void progdescription() {
    cout << "Programming Exercise 05" << endl;
    cout << "Submitted by: Renz Jaepril G. Mongaya" << endl;
    cout << "CMSC 28 K-1L" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Program will ask the user to input maximum of numbers (positive or negative but not zero)" << endl;
	cout << "It will perform basic statistics on these numbers." << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
}

// Function to read data into an array
void readdata(int (&Array)[10], int &count) {
    cout << "Input integers (enter 0 to stop):\n";
    int num;

    while (count < 10) {
        cout << "Input integer " << (count + 1) << ": ";
        cin >> num;
        
        if (num == 0) {
            cout << "Stopping input." << endl; //input 0 to stop
            break;
        }
        
        Array[count] = num;
        count++;
    }
}

// Function to find the largest value in the array
int getLarge(int Array[10], int count) {
    if (count == 0) return 0; // Return 0 if no elements entered
    int largest = Array[0];
    for (int i = 1; i < count; ++i) {
        if (Array[i] > largest) {
            largest = Array[i];
        }
    }
    return largest;
}

// Function to find the smallest value in the array
int getsmall(int Array[10], int count) {
    if (count == 0) return 0; // Return 0 if no elements entered
    int smallest = Array[0];
    for (int i = 1; i < count; ++i) {
        if (Array[i] < smallest) {
            smallest = Array[i];
        }
    }
    return smallest;
}

// Function to calculate the average of the array elements
float average(int Array[10], int count) {
    if (count == 0) return 0; // Return 0 if no elements entered
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += Array[i];
    return (float)sum / count;
}

// Function to calculate the variance of the array elements
float var(int Array[10], float mean, int count) {
    if (count <= 1) return 0; // Return 0 if only one or no elements entered
    float variance = 0;
    for (int i = 0; i < count; i++) {
        variance += (Array[i] - mean) * (Array[i] - mean); 
    }
    return variance / (count - 1);
}

// Babylonian method for square root (built-in functions is not allowed)
float standev(float n) {
    float x = n;
    float y = 1;
    float e = 0.000001;
    while (x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

int main() {
    // Display program description
    progdescription();

    int inputArray[10]; // Declare an array to store integers
    int count = 0; // Counter to keep track of the number of elements entered
    readdata(inputArray, count); // Call to read data into the array

    int largeVal = getLarge(inputArray, count); // Find the largest value in the array
    cout << ""<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Largest integer: " << largeVal << endl;

    int smallVal = getsmall(inputArray, count); // Find the smallest value in the array
    cout << "Smallest integer: " << smallVal << endl;

    // Calculate and print the average
    float ave = average(inputArray, count);
    cout << "Average: " << ave << endl;

    // Calculate and print the variance
    float variance = var(inputArray, ave, count);
    cout << "Sample variance: " << variance << endl;

    // Calculate and print the standard deviation
    float stdev = standev(variance);
    cout << "Standard deviation: " << stdev << endl;

    return 0;
}
