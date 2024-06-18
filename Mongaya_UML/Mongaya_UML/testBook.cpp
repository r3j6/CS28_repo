#include <iostream>
#include <string>
#include "Book.h" // Include the header file for the Book class (Book.h)
using namespace std;

int main() {
    string title, author, ISBN, publisher;
    cout << "Programming Exercise 06" << endl;
    cout << "Submitted by: Renz Jaepril G. Mongaya" << endl;
    cout << "CMSC 28 K-1L" << endl;
    //Input Title
    cout << "\nInput title: ";
    getline(cin, title);
    //Input Author
    cout << "Input author: ";
    getline(cin, author);
    //Input ISBN
    cout << "Input ISBN: ";
    getline(cin, ISBN); 

    // Create a Book object using the provided details
    Book tryBook(title, author, ISBN);
    //Input Publisher
    cout << "Input publisher: ";
    getline(cin, publisher); 
    tryBook.setPublisher(publisher);

    // Display book details
    cout << "\nBook details:" << endl;
    cout << "Title: " << tryBook.getTitle() << endl;
    cout << "Author: " << tryBook.getAuthor() << endl;
    cout << "ISBN: " << tryBook.getISBN() << endl;
    cout << "Publisher: " << tryBook.getPublisher() << endl;

    return 0;
}

