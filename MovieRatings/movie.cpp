#include <string>
#include "movie.h"

using namespace std;

Movie::Movie(string initial_name, string initial_rating, int initial_watched)
    : name(initial_name), rating(initial_rating), watched(initial_watched)
{
}

Movie::~Movie()
{
}

Movie::Movie(const Movie &source)
    : name(source.name), rating(source.rating), watched(source.watched)
{
}

Movie::Movie(Movie &&source) noexcept
    : name(source.name), rating(source.rating), watched(source.watched)
{
}