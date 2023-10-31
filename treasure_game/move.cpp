#include <iostream>
#include <vector>
#include "player_function_definitions.h"

using namespace std;


void move_player(const vector<Player*>& players, int active_player_number,
				 const vector<int>& trapdoor_coordinates_x, const vector<int>& trapdoor_coordinates_y,
				 const vector<int>& treasure_coordinates_x, const vector<int>& treasure_coordinates_y,
				 const vector<int>& walls_coordinates_x, const vector<int>& walls_coordinates_y)
{
	char direction;
	cin >> direction;

	// Get current players
	Player* player = players[active_player_number];

	switch (direction)
	{
	case 'N':
		player->x_coordinate -= 1;
		break;
	case 'E':
		player->y_coordinate += 1;
		break;
	case 'S':
		player->x_coordinate += 1;
		break;
	case 'W':
		player->y_coordinate -= 1;
		break;
	default:
		cout << "Wrong direction!" << endl;
		break;
	}

	int current_x_coordinate = player->x_coordinate;
	int current_y_coordinate = player->y_coordinate;


	// Check if player see trapdoor
	player_see_trapdoor(current_x_coordinate, current_y_coordinate, trapdoor_coordinates_x, trapdoor_coordinates_y);

	// Chcek if player entered a trapdoor
	if (player_entered_trapdoor(current_x_coordinate, current_y_coordinate, trapdoor_coordinates_x, trapdoor_coordinates_y))
	{
		cout << "Player " << active_player_number + 1 << " lost" << endl;
		player->lost = true;
	}

	// Check if player see a treasure
	player_see_treasure(current_x_coordinate, current_y_coordinate, treasure_coordinates_x, treasure_coordinates_y);

	// Check if player is standing on the treasure
	if (player_stands_on_treasure(current_x_coordinate, current_y_coordinate, treasure_coordinates_x, treasure_coordinates_y))
	{
		cout << "You stand on treasure." << endl;
		player->stands_on_the_treasure = true;
	}
	else 
	{
		player->stands_on_the_treasure = false;
	}
}