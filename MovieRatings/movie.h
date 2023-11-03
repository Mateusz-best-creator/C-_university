#pragma once
#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watched;

public:
    // Define constructor
    Movie(std::string initial_name = "UNKNOWN", std::string initial_rating = "GOOD", int initial_watched = 0);
    // Define destructor
    ~Movie();
    // Define copy consturctor
    Movie(const Movie &source);
    // Define move constructor
    Movie(Movie &&source) noexcept;

    // Define some getters
    std::string get_name() { return name; }
    std::string get_rating() { return rating; }
    int get_watched() { return watched; }
    void increment_watched() { ++watched; }
};