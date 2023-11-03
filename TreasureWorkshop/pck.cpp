#include <iostream>
#include <vector>
#include "./player_function_definitions.h"

using namespace std;

void PCK_command(vector<Player *> &players, int active_player_number)
{
    if (players[active_player_number]->stands_on_the_treasure)
    {
        players[active_player_number]->has_treasure = 'T';
    }
}