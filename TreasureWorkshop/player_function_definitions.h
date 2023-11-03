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
void check_password(Player *player, char secret_password);

// This function allow player to move
void move_player(const vector<Player *> &players, int active_player_number,
                 const vector<int> &trapdoor_coordinates_x, const vector<int> &trapdoor_coordinates_y,
                 const vector<int> &treasure_coordinates_x, const vector<int> &treasure_coordinates_y,
                 const vector<int> &walls_coordinates_x, const vector<int> &walls_coordinates_y);

// This functions allows active player to pick a treasure
void PCK_command(vector<Player *> &players, int active_player_number);

// This function allows us to print all available commands in our game
void print_available_commands();

// This function prints info about the game and about the players
void PRT_command(vector<Player *> &players, int active_player_number,
                 vector<int> &trapdoor_coordinates_x, vector<int> &trapdoor_coordinates_y,
                 vector<int> &treasure_coordinates_x, vector<int> &treasure_coordinates_y,
                 vector<int> &walls_coordinates_x, vector<int> &walls_coordinates_y);

// Function that allows us to add any object to the game (like wall, treasure, trapdoor)
void add_object_to_game(vector<int> &coordinates_x, vector<int> &coordinates_y, const string &object_name);

// Functions that allows us to tell if player see an object or is standing on an object
void player_see(Player *player, int coordinate_x, int coordinate_y, vector<int> coordinates_x, vector<int> coordinates_y, const string &object_name);
bool player_stands(int coordinate_x, int coordinate_y, vector<int> coordinates_x, vector<int> coordinates_y);

// Function to reset the entire state of the game
void NDS_command(vector<Player *> &players,
                 vector<int> &trapdoor_coordinates_x, vector<int> &trapdoor_coordinates_y,
                 vector<int> &treasure_coordinates_x, vector<int> &treasure_coordinates_y,
                 vector<int> &walls_coordinates_x, vector<int> &walls_coordinates_y);

// Function for adding players
void NPS_command(vector<Player *> &players);