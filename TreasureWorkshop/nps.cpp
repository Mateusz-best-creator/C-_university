#include <iostream>
#include <vector>
#include "player_function_definitions.h"

const static int MAX_NUMBER_OF_PLAYERS = 100;

using namespace std;

void NPS_command(vector<Player*>& players)
{
	int number_of_players;
	cin >> number_of_players;
	if (number_of_players > MAX_NUMBER_OF_PLAYERS)
	{
		cout << "Exceeded number of players." << endl;
	}
	else
	{
		for (int i = 0; i < number_of_players; ++i)
		{
			int coordinate_y, coordinate_x;
			cin >> coordinate_x >> coordinate_y;

			// Create new player and initialize it's coordinates
			Player* player = new Player();
			player->initial_x_coordinate = coordinate_x;
			player->initial_y_coordinate = coordinate_y;
			player->x_coordinate = coordinate_x;
			player->y_coordinate = coordinate_y;
			players.push_back(player);
		}
	}
}
