#include <iostream>
#include <vector>
#include "player_function_definitions.h"

using namespace std;

void PCK_command(vector<Player*>& players, int active_player_number,
	vector<int>& treasure_coordinates_x, vector<int>& treasure_coordinates_y)
{
	Player* active_player = players[active_player_number];
	if (active_player->stands_on_the_treasure)
	{
		active_player->has_treasure = 'T';

		for (size_t i = 0; i < treasure_coordinates_x.size(); ++i)
		{
			if (treasure_coordinates_x[i] == active_player->x_coordinate && treasure_coordinates_y[i] == active_player->y_coordinate)
			{
				// Then we want to remove value from treasure coordinates at index i
				treasure_coordinates_x.erase(treasure_coordinates_x.begin() + i);
				treasure_coordinates_y.erase(treasure_coordinates_y.begin() + i);
			}
		}
	}

}
