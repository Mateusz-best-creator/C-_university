#include <iostream>
#include <vector>
#include "player_function_definitions.h"

const static int MAX_NUMBER_OF_WALLS = 100;

using namespace std;

bool prevent_collision_between_player_and_wall(int current_coordinate_x, int current_coordinate_y,
                                               const vector<int>& walls_coordinate_x, const vector<int>& walls_coordinate_y)
{
    for (int i = 0; i < walls_coordinate_x.size(); ++i)
    {
        if (current_coordinate_x == walls_coordinate_x[i] && current_coordinate_y == walls_coordinate_y[i])
        {
            return false;
        }
    }
    return true;
}

void player_see_trapdoor(int coordinate_x, int coordinate_y, vector<int> trapdoor_coordinates_x, vector<int> trapdoor_coordinates_y)
{
    for (int i = 0; i < trapdoor_coordinates_x.size(); ++i)
    {
        if ((coordinate_x + 1 == trapdoor_coordinates_x[i] && coordinate_y == trapdoor_coordinates_y[i]
		|| coordinate_x - 1 == trapdoor_coordinates_x[i] && coordinate_y == trapdoor_coordinates_y[i]
		|| coordinate_x == trapdoor_coordinates_x[i] && coordinate_y + 1 == trapdoor_coordinates_y[i]
		|| coordinate_x == trapdoor_coordinates_x[i] && coordinate_y - 1 == trapdoor_coordinates_y[i]))
        {
            cout << "You see a trapdoor at (" << trapdoor_coordinates_x[i] << "," << trapdoor_coordinates_y[i] << ")" << endl;
        }
    }
}

bool player_entered_trapdoor(int coordinate_x, int coordinate_y, vector<int> trapdoor_coordinates_x, vector<int> trapdoor_coordinates_y)
{
    for (int i = 0; i < trapdoor_coordinates_x.size(); ++i)
    {
        if (coordinate_x == trapdoor_coordinates_x[i] && coordinate_y == trapdoor_coordinates_y[i])
        {
            return true;
        }
    }
    return false;
}

void player_see_treasure(int coordinate_x, int coordinate_y, vector<int> treasure_coordinates_x, vector<int> treasure_coordinates_y)
{
    for (int i = 0; i < treasure_coordinates_x.size(); ++i)
    {
        if ((coordinate_x + 1 == treasure_coordinates_x[i] && coordinate_y == treasure_coordinates_y[i]
		|| coordinate_x - 1 == treasure_coordinates_x[i] && coordinate_y == treasure_coordinates_y[i]
		|| coordinate_x == treasure_coordinates_x[i] && coordinate_y + 1 == treasure_coordinates_y[i]
		|| coordinate_x == treasure_coordinates_x[i] && coordinate_y - 1 == treasure_coordinates_y[i]))
        {
            cout << "You see a treasure at (" << treasure_coordinates_x[i] << "," << treasure_coordinates_y[i] << ")" << endl;
        }
    }
}

bool player_stands_on_treasure(int coordinate_x, int coordinate_y, vector<int> treasure_coordinates_x, vector<int> treasure_coordinates_y)
{
    for (int i = 0; i < treasure_coordinates_x.size(); ++i)
    {
        if (coordinate_x == treasure_coordinates_x[i] && coordinate_y == treasure_coordinates_y[i])
        {
            return true;
        }
    }
    return false;
}