#include <iostream>
#include <string>
#include <vector>

#include "player_function_definitions.h"

using namespace std;

// Reset the entire game
void NDS_command(vector<Player *> &players,
                 vector<int> &trapdoor_coordinates_x, vector<int> &trapdoor_coordinates_y,
                 vector<int> &treasure_coordinates_x, vector<int> &treasure_coordinates_y,
                 vector<int> &walls_coordinates_x, vector<int> &walls_coordinates_y)
{
    // Free the memory
    for (size_t i = 0; i < players.size(); ++i)
    {
        delete players[i];
    }

    // Clear all vectors
    players.clear();
    trapdoor_coordinates_x.clear();
    trapdoor_coordinates_y.clear();
    treasure_coordinates_x.clear();
    treasure_coordinates_y.clear();
    walls_coordinates_x.clear();
    walls_coordinates_y.clear();
}