#include <iostream>
#include <string>
#include <vector>

#include "movies.h"

using namespace std;

void Movies::add_movie(string name, string rating, int watched_count)
{
    bool arleady_in = false;
    for (auto movie : all_movies)
    {
        if (movie->get_name() == name)
        {
            arleady_in = true;
            break;
        }
    }
    if (arleady_in)
    {
        cout << "Movie : " << name << " is arleady added to the list." << endl;
    }
    else
    {
        Movie *new_movie = new Movie(name, rating, watched_count);
        all_movies.push_back(new_movie);
    }
}

void Movies::increment_watched_count(string name)
{
    bool name_in_list = false;
    for (vector<Movie *>::iterator itr = all_movies.begin(); itr != all_movies.end(); ++itr)
    {
        if ((*itr)->get_name() == name)
        {
            (*itr)->increment_watched();
            name_in_list = true;
            break;
        }
    }

    if (!name_in_list)
    {
        cout << "Movie : " << name << " is not in our list." << endl;
    }
}

void Movies::display_all_movies()
{
    cout << "\n-----------\n";
    for (auto movie : all_movies)
    {
        cout << "Name : " << movie->get_name() << endl;
        cout << "Rating : " << movie->get_rating() << endl;
        cout << "Watched : " << movie->get_watched() << endl;
    }
}