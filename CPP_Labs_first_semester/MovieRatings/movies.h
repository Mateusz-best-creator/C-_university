#pragma once
#include <vector>
#include <string>

#include "movie.h"

class Movies
{
private:
    std::vector<Movie *> all_movies;

public:
    void add_movie(std::string name, std::string rating, int watched_count);
    void increment_watched_count(std::string name);
    void display_all_movies();
};