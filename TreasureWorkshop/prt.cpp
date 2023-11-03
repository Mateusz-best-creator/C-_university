#include <iostream>
#include <string>
#include <vector>
#include "player_function_definitions.h"

using namespace std;

static void print_info(Player *player, int active_player_number, int index_of_player)
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
    cout << "Entered: " << player->entered << " "
         << "Lost: " << player->lost << " ";
    cout << "Has Treasure: " << player->has_treasure << " "
         << "Won Game: " << player->won_game << endl;
}

// Define constand and static sizes of the board

static const int HEIGHT = 11;
static const int WIDTH = 11;

void update_board(char board[HEIGHT][WIDTH], const vector<int> &object_coordinates_x, const vector<int> &object_coordinates_y, char symbol)
{
    for (size_t i = 0; i < object_coordinates_x.size(); ++i)
    {
        // +5 beacuse of the way how our board is centralized
        board[object_coordinates_x[i] + 5][object_coordinates_y[i] + 5] = symbol;
    }
}

void print_entire_board(int mode, const vector<Player *> &players, int active_player_number,
                        vector<int> &trapdoor_coordinates_x, vector<int> &trapdoor_coordinates_y,
                        vector<int> &treasure_coordinates_x, vector<int> &treasure_coordinates_y,
                        vector<int> &walls_coordinates_x, vector<int> &walls_coordinates_y)
{
    // Initialize our board
    char board[HEIGHT][WIDTH] = {
'.','.','.','.','.','.','.','.','.','.','.',
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
'.','.','.','.','.','.','.','.','.','.','.', 
};

    // Update our board with appropriate characters
    update_board(board, walls_coordinates_x, walls_coordinates_y, '#');
    update_board(board, treasure_coordinates_x, treasure_coordinates_y, '+');
    update_board(board, trapdoor_coordinates_x, trapdoor_coordinates_y, '_');

    // Print the ^ symbol for a given player
    board[players[active_player_number]->initial_y_coordinate + 5][players[active_player_number]->initial_x_coordinate + 5] = '^';

    char counter_char[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int counter = 0;
    // Current positions of players, use iterators to practice :)
    for (vector<Player *>::const_iterator player = players.begin(); player != players.end(); ++player)
    {
        board[(*player)->x_coordinate + 5][(*player)->y_coordinate + 5] = counter_char[counter];
        counter++;
    }

    for (size_t i = 0; i < HEIGHT; ++i)
    {
        for (size_t j = 0; j < WIDTH; ++j)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void PRT_command(vector<Player *> &players, int active_player_number,
                 vector<int> &trapdoor_coordinates_x, vector<int> &trapdoor_coordinates_y,
                 vector<int> &treasure_coordinates_x, vector<int> &treasure_coordinates_y,
                 vector<int> &walls_coordinates_x, vector<int> &walls_coordinates_y)
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
        if (x[0] == '0')
        {
            print_info(players[active_player_number], active_player_number + 1, -1);
        }
        else if (x[0] == '1')
        {
            for (size_t i = 0; i < players.size(); ++i)
            {
                print_info(players[i], active_player_number + 1, i + 1);
            }
        }

        // Beacuse of ASCII codes we have to subtract 48
        int mode = (int)x[x.size() - 1] - 48;
        // cout << "MODE: " << mode << endl;
        print_entire_board(mode, players, active_player_number,
                           trapdoor_coordinates_x, trapdoor_coordinates_y,
                           treasure_coordinates_x, treasure_coordinates_y,
                           walls_coordinates_x, walls_coordinates_y);
    }
}
