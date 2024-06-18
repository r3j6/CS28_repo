#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string synopsis;
    string mpaaRating;
    string genre;
    Person director;
    Person actor;

public:
    // Constructor
    Movie(const string &title, const string &synopsis, const string &mpaaRating, const string &genre, const Person &director, const Person &actor)
        : title(title), synopsis(synopsis), mpaaRating(mpaaRating), genre(genre), director(director), actor(actor) {}

    // Accessor methods
    string getTitle() const {
        return title;
    }

    string getSynopsis() const {
        return synopsis;
    }

    string getMpaaRating() const {
        return mpaaRating;
    }

    string getGenre() const {
        return genre;
    }

    Person getDirector() const {
        return director;
    }

    Person getActor() const {
        return actor;
    }
};

#endif

