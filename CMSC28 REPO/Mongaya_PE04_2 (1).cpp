#include <iostream>
using namespace std;

//Program description
void progdescription() {
    cout << "Program that converts integer value into binary." << endl;
    cout << "By: Renz Jaepril G. Mongaya" << endl;
    cout << "04/28/2024" << endl;
    cout << "CMSC 28 K-1L" << endl;
    cout << endl;
}
//Read Input data
void readdata (int &dec){
	cout << "Input Decimal Value:";
	cin >> dec;
	}

//Convert Decimal to Binary
void DecToBin (int n) {
	
	int bin[100];
	
	int i = 0;
	while (n>0) {
		bin[i] = n % 2;
		n = n / 2;
		i++;
	}
	//Show Result
	cout << "The Binary equivalent of the Decimal Value is: " ;
	for (int j = i - 1; j >= 0; j--) {
        cout << bin[j];
    }
   		cout << endl;

	}

int main() {
    // Variable declaration
    int dec;

    // Display program description
    progdescription();

    // Ask for input
    readdata(dec);

    // Convert decimal to binary
    DecToBin(dec);

    return 0;
}
