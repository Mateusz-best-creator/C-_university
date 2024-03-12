#include <iostream>
#include <vector>
#include "player_function_definitions.h"

using namespace std;

void display_user_encounter_wall()
{
    cout << "Can't move there, you will be standing on the wall, loosing move." << endl;
}

void move_player(const vector<Player*>& players, int active_player_number,
    const vector<int>& trapdoor_coordinates_x, const vector<int>& trapdoor_coordinates_y,
    const vector<int>& treasure_coordinates_x, const vector<int>& treasure_coordinates_y,
    const vector<int>& walls_coordinates_x, const vector<int>& walls_coordinates_y,
    vector<int>& lost_players_indexes)
{
    char direction;
    cin >> direction;

    // Get current players
    Player* player = players[active_player_number];

    int before_move_x_coordinate = player->x_coordinate;
    int before_move_y_coordinate = player->y_coordinate;

    // In each step we check if user is able to move in certain direction (is there is no wall he can move, othwerwise he cannot and we print some message)
    switch (direction)
    {
    case 'N':
        if (!player_stands(before_move_x_coordinate - 1, before_move_y_coordinate, walls_coordinates_x, walls_coordinates_y))
        {
            player->x_coordinate -= 1;
        }
        else
        {
            display_user_encounter_wall();
        }
        break;
    case 'E':
        if (!player_stands(before_move_x_coordinate, before_move_y_coordinate + 1, walls_coordinates_x, walls_coordinates_y))
        {
            player->y_coordinate += 1;
        }
        else
        {
            display_user_encounter_wall();
        }
        break;
    case 'S':
        if (!player_stands(before_move_x_coordinate + 1, before_move_y_coordinate, walls_coordinates_x, walls_coordinates_y))
        {
            player->x_coordinate += 1;
        }
        else
        {
            display_user_encounter_wall();
        }
        break;
    case 'W':
        if (!player_stands(before_move_x_coordinate, before_move_y_coordinate - 1, walls_coordinates_x, walls_coordinates_y))
        {
            player->y_coordinate -= 1;
        }
        else
        {
            display_user_encounter_wall();
        }
        break;
    default:
        cout << "Wrong direction!" << endl;
        break;
    }

    int current_x_coordinate = player->x_coordinate;
    int current_y_coordinate = player->y_coordinate;

    // Check if player see trapdoor
    const string trapdoor_string = "trapdoor";
    player_see(player, current_x_coordinate, current_y_coordinate, trapdoor_coordinates_x, trapdoor_coordinates_y, trapdoor_string);

    // Chcek if player entered a trapdoor
    if (player_stands(current_x_coordinate, current_y_coordinate, trapdoor_coordinates_x, trapdoor_coordinates_y))
    {
        cout << "Player " << active_player_number + 1 << " lost" << endl;
        player->lost = 'T';
        // Here we have to keep track of players that lost
        lost_players_indexes.push_back(active_player_number);
        return;
    }

    // Check if player see a treasure
    const string treasure_string = "treasure";
    player_see(player, current_x_coordinate, current_y_coordinate, treasure_coordinates_x, treasure_coordinates_y, treasure_string);

    // Check if player is standing on the treasure
    if (player_stands(current_x_coordinate, current_y_coordinate, treasure_coordinates_x, treasure_coordinates_y))
    {
        // cout << "You stand on treasure." << endl;
        player->stands_on_the_treasure = true;
    }
    else
    {
        player->stands_on_the_treasure = false;
    }

    if (player->initial_x_coordinate == player->x_coordinate && player->initial_y_coordinate == player->y_coordinate && player->has_treasure == 'T')
    {
        cout << "Player " << active_player_number + 1 << " won" << endl;
        player->won_game = 'T';
    }
}
