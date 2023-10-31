#pragma once
#include <vector>
#include <string>

using namespace std;

struct Player
{
	int initial_x_coordinate = 0;
	int initial_y_coordinate = 0;
	int x_coordinate = initial_x_coordinate;
	int y_coordinate = initial_y_coordinate;
	char entered = 'F';
	bool stands_on_the_treasure = false;
	char has_treasure = 'F';
	char won_game = 'F';
	char lost = 'F';
};

// This function allow us to check if user correctly entered a password
void check_password(Player* player, char secret_password, int& which_player);

// This function allow player to move
void move_player(const vector<Player*>& players, int active_player_number,
				 const vector<int>& trapdoor_coordinates_x, const vector<int>& trapdoor_coordinates_y,
				 const vector<int>& treasure_coordinates_x, const vector<int>& treasure_coordinates_y,
				 const vector<int>& walls_coordinates_x, const vector<int>& walls_coordinates_y);

// This functions allows active player to pick a treasure
void PCK_command(vector<Player*>& players, int active_player_number);

// This function allows us to print all available commands in our game
void print_available_commands();

// This function allows us to print informations about our players (it is used inside PRT_command function)
void print_info(Player* player, int active_player_number);

// This function prints info about the game and about the players
void PRT_command(vector<Player*>& players, int active_plater_number);

// Function for adding players
void add_players(vector<Player*>& players);

// This function allow us to prevent the collsions between walls and the players
bool prevent_collision_between_player_and_wall(int current_coordinate_x, int current_coordinate_y, 
											   vector<int>& walls_coordinate_x, vector<int>& walls_coordinate_y);

// Function that allows us to add any object to the game (like wall, treasure, trapdoor)
void add_object_to_game(vector<int>& coordinates_x, vector<int>& coordinates_y, string object_name);

void player_see_trapdoor(int coordinate_x, int coordinate_y, vector<int> trapdoor_coordinates_x, vector<int> trapdoor_coordinates_y);
bool player_entered_trapdoor(int coordinate_x, int coordinate_y, vector<int> trapdoor_coordinates_x, vector<int> trapdoor_coordinates_y);
void player_see_treasure(int coordinate_x, int coordinate_y, vector<int> treasure_coordinates_x, vector<int> treasure_coordinates_y);
bool player_stands_on_treasure(int coordinate_x, int coordinate_y, vector<int> treasure_coordinates_x, vector<int> treasure_coordinates_y);