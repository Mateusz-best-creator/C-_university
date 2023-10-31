#include <iostream>
#include <vector>
#include "player_function_definitions.h"

using namespace std;

static void print_info(Player* player, int active_player_number, int index_of_player)
{
	if (index_of_player == active_player_number || index_of_player == -1)
	{
		cout << "Active Player: " << active_player_number << " ";
	}
	else
	{
		cout << "Player: " << index_of_player << " ";
	}
	cout << "Coordinates: " << player->x_coordinate << ", " << player->y_coordinate << " ";
	cout << "Entered: " << player->entered << " " << "Lost: " << player->lost << " ";
	cout << "Has Treasure: " << player->has_treasure << " " << "Won Game: " << player->won_game << endl;
}


void PRT_command(vector<Player*>& players, int active_player_number)
{
	char x;
	cin >> x;
	if (x == '0' || x == '-')
	{
		// In tests we count players from 1 so I have to add 1 :(
		print_info(players[active_player_number], active_player_number + 1, -1);
	}
	else if (x == '1')
	{
		for (int i = 0; i < players.size(); ++i)
		{
			print_info(players[i], active_player_number+1, i+1);
		}
	}
}