#include <iostream>
#include <string>

#include "movies.h"

using namespace std;

int main()
{
    cout << "Select an option: " << endl;
    cout << "[A] -> add movie" << endl;
    cout << "[I] -> increment counter of a given movie" << endl;
    cout << "[D] -> display all movies" << endl;
    cout << "[Q/q] -> quit the program" << endl;
    char option;

    string title;
    string rating;
    int watched;

    Movies *movies = new Movies();

    bool working = true;

    while (working)
    {
        cin >> option;
        switch (option)
        {
        case 'A':
            cin.ignore();
            cout << "Title : ";
            getline(cin, title);
            cout << "Rating: ";
            cin >> rating;
            cout << "Watched counter : ";
            cin >> watched;
            movies->add_movie(title, rating, watched);
            break;

        case 'I':
            cin.ignore();
            cout << "Title : ";
            getline(cin, title);
            movies->increment_watched_count(title);
            break;

        case 'D':
            movies->display_all_movies();
            break;

        default:
            working = false;
            break;
        }
    }
}
