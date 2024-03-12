#include <iostream>
#include <string>
#include <vector>
#include "player_function_definitions.h"

const static int MAX_NUMBER_OF_WALLS = 100;

using namespace std;

void player_see(Player* player, int coordinate_x, int coordinate_y, vector<int> coordinates_x, vector<int> coordinates_y, const string& object_name)
{
    for (size_t i = 0; i < coordinates_x.size(); ++i)
    {
        if ((coordinate_x + 1 == coordinates_x[i] && coordinate_y == coordinates_y[i] || 
            coordinate_x - 1 == coordinates_x[i] && coordinate_y == coordinates_y[i] || 
            coordinate_x == coordinates_x[i] && coordinate_y + 1 == coordinates_y[i] ||
            coordinate_x == coordinates_x[i] && coordinate_y - 1 == coordinates_y[i]) && 
            player->has_treasure == 'F' ||
            (coordinate_x == coordinates_x[i] && coordinate_y == coordinates_y[i] && object_name != "trapdoor"))
        {
            cout << "You see a " << object_name << " at (" << coordinates_x[i] << "," << coordinates_y[i] << ")" << endl;
        }
    }
}

bool player_stands(int coordinate_x, int coordinate_y, vector<int> coordinates_x, vector<int> coordinates_y)
{
    for (size_t i = 0; i < coordinates_x.size(); ++i)
    {
        if (coordinate_x == coordinates_x[i] && coordinate_y == coordinates_y[i])
        {
            return true;
        }
    }
    return false;
}
