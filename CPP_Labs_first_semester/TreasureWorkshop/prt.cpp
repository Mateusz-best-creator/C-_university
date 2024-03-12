#include <iostream>
#include <string>
#include <vector>
#include "player_function_definitions.h"

using namespace std;

// Create global variable for mode
static int MODE;

// Create two global variables that will shift every element on the board based on current position of active player
int SHIFT_UP;
int SHIFT_RIGHT;

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

bool check_if_in_board(int x_coordinate, int y_coordinate)
{
	if (x_coordinate >= MODE * 2 + 1 || y_coordinate >= MODE * 2 + 1)
	{
		return false;
	}
	return true;
}

void update_board(vector<vector<char>>& board, const vector<int>& object_coordinates_x, const vector<int>& object_coordinates_y, char symbol)
{
	for (size_t i = 0; i < object_coordinates_x.size(); ++i)
	{
		if (!check_if_in_board(object_coordinates_x[i] + MODE + SHIFT_UP, object_coordinates_y[i] + MODE + SHIFT_RIGHT))
		{
			return;
		}
		// +MODE beacuse of the way how our board is centralized
		board[object_coordinates_x[i] + MODE + SHIFT_UP][object_coordinates_y[i] + MODE + SHIFT_RIGHT] = symbol;
	}
}

void print_players(vector<vector<char>>& board, const vector<Player*>& players)
{
	char counter_char[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int counter = 0;
	// Prining Current positions of players
	for (auto player : players)
	{
		int x_coordinate = player->x_coordinate;
		int y_coordinate = player->y_coordinate;
		if (!check_if_in_board(x_coordinate + MODE + SHIFT_UP, y_coordinate + MODE + SHIFT_RIGHT))
		{
			continue;
		}
		else
		{
			board[x_coordinate + MODE + SHIFT_UP][y_coordinate + MODE + SHIFT_RIGHT] = counter_char[counter];
		}
		counter++;
	}
}

void print_initial_active_position(vector<vector<char>>& board, Player* player)
{
	// Print the ^ symbol for a given player
	int x_coordinate = player->initial_x_coordinate;
	int y_coordinate = player->initial_y_coordinate;
	if (!check_if_in_board(x_coordinate + MODE + SHIFT_UP, y_coordinate + MODE + SHIFT_RIGHT))
	{
		return;
	}
	else
	{
		board[x_coordinate + MODE + SHIFT_UP][y_coordinate + MODE + SHIFT_RIGHT] = '^';
	}
}

void print_entire_board(const vector<Player*>& players, int active_player_number,
	vector<int>& trapdoor_coordinates_x, vector<int>& trapdoor_coordinates_y,
	vector<int>& treasure_coordinates_x, vector<int>& treasure_coordinates_y,
	vector<int>& walls_coordinates_x, vector<int>& walls_coordinates_y)
{
	// Determine HEIGHT and WIDTH based on mode
	int HEIGHT, WIDTH;
	HEIGHT = WIDTH = MODE * 2 + 1;

	// Initilize our board
	vector<vector<char>> board(HEIGHT, std::vector<char>(WIDTH, '.'));

	SHIFT_UP = -players[active_player_number]->x_coordinate;
	SHIFT_RIGHT = -players[active_player_number]->y_coordinate;


	// Update our board with appropriate characters
	update_board(board, walls_coordinates_x, walls_coordinates_y, '#');
	update_board(board, treasure_coordinates_x, treasure_coordinates_y, '+');
	update_board(board, trapdoor_coordinates_x, trapdoor_coordinates_y, '_');
	print_initial_active_position(board, players[active_player_number]);
	print_players(board, players);
	
	
	// Print the content of the board
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

void PRT_command(vector<Player*>& players, int active_player_number,
				vector<int>& trapdoor_coordinates_x, vector<int>& trapdoor_coordinates_y,
				vector<int>& treasure_coordinates_x, vector<int>& treasure_coordinates_y,
				vector<int>& walls_coordinates_x, vector<int>& walls_coordinates_y)
{
	string x;
	getline(cin, x, '\n');

	// Trim leading and trailing white spaces (kinda crazy :) )
	x.erase(0, x.find_first_not_of(" \t\r\n"));
	x.erase(x.find_last_not_of(" \t\r\n") + 1);

	if (x == "0" || x == "-")
	{
		// In tests we count players from 1 so I have to add 1 :(
		print_info(players[active_player_number], active_player_number + 1, -1);
	}
	else if (x == "1")
	{
		for (size_t i = 0; i < players.size(); ++i)
		{
			print_info(players[i], active_player_number + 1, i + 1);
		}
	}
	else
	{
		if (x == "0")
		{
			print_info(players[active_player_number], active_player_number + 1, -1);
		}
		else
		{
			// Beacuse of ASCII codes we have to subtract 48
			MODE = (int)x[x.size() - 1] - 48;
			if (x[0] == '0')
			{
				print_info(players[active_player_number], active_player_number + 1, -1);
				print_entire_board(players, active_player_number,
					trapdoor_coordinates_x, trapdoor_coordinates_y,
					treasure_coordinates_x, treasure_coordinates_y,
					walls_coordinates_x, walls_coordinates_y);
			}
			else
			{
				for (size_t i = 0; i < players.size(); ++i)
				{
					print_info(players[i], active_player_number + 1, i + 1);
					print_entire_board(players, i,
						trapdoor_coordinates_x, trapdoor_coordinates_y,
						treasure_coordinates_x, treasure_coordinates_y,
						walls_coordinates_x, walls_coordinates_y);
				}
			}
		}
		
		
	}
}
