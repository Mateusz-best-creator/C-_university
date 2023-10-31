#include <iostream>
#include "player_function_definitions.h"

using namespace std;

void print_available_commands()
{
	cout << "Printing available commands: " << endl;
	cout << "[PSS] - user enters the secret password." << endl;
	cout << "[MOV] - Argument: x. Moves current player, the direction, given as argument x are N, E, S, W. If a player is at distance at most one field from treasure or from a trapdoor, then the game prints an information. If a player enters a trapdoor, then the player loses." << endl;
	cout << "[PCK] -  Pick a treasure. Provided that a player stands on a treasure, the player can pick it." << endl;
	cout << "[PRT] - Argument x. If x == 0 prints the coordinates of active player. If x == 1 prints the coordinates of all players. Moreover, it shows if the player entered the area. Finally it shows which player is active." << endl;
	cout << "[SKP] - Skip turn -- the player does nothing." << endl;
	cout << "[END] - Quits the game." << endl;
	cout << "[HLP] - Print the available commands. If there is some unknown command stated also print this help and quit the program." << endl;
}