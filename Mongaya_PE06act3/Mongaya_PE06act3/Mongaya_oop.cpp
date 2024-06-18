#include <iostream>
#include <string>
#include "Person.h"
#include "Movie.h"

using namespace std;

int main() {
    string title;
    string synopsis;
    string mpaaRating;
    string genre;
    string directorFname;
    string directorLname;
    string actorFname;
    string actorLname;

    cout << "MOVIE REVIEW\n";
    cout << "Programmed by: Renz Jaepril Mongaya\n";
    cout << "K-1L\n";
    cout << "===============================================\n";

    cout << "Enter Movie Title: ";
    getline(cin, title);

    cout << "Enter Synopsis: ";
    getline(cin, synopsis);

    cout << "MPAA Rating: ";
    getline(cin, mpaaRating);

    cout << "Genre: ";
    getline(cin, genre);

    cout << "Director's First Name: ";
    getline(cin, directorFname);
    cout << "Director's Last Name: ";
    getline(cin, directorLname);

    cout << "First name of the Actor/actress: ";
    getline(cin, actorFname);
    cout << "Last name of the Actor/actress: ";
    getline(cin, actorLname);

    // Create Person objects for director and actor
    Person director(directorFname, directorLname);
    Person actor(actorFname, actorLname);

    // Create a Movie object
    Movie movie(title, synopsis, mpaaRating, genre, director, actor);

    // Output movie information
    cout << "===============================================\n\n";
    cout << "\nMOVIE DETAILS\n";
    cout << "Movie Title: " << movie.getTitle() << endl;
    cout << "Synopsis: " << movie.getSynopsis() << endl;
    cout << "MPAA Rating: " << movie.getMpaaRating() << endl;
    cout << "Genre: " << movie.getGenre() << endl;
    cout << "Director: " << movie.getDirector().getFname() << " " << movie.getDirector().getLname() << endl;
    cout << "Actor: " << movie.getActor().getFname() << " " << movie.getActor().getLname() << endl;

    return 0;
}

