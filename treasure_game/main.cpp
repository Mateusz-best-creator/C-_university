#include <iostream>
#include <string>
#include <vector>

// Upload our functions
#include "player_function_definitions.h"

using namespace std;

// Constants about the treasure and the walls
int wall1_y = 0;
int wall1_x = -5;

int wall2_y = 3;
int wall2_x = -3;

int treasure_y = 0;
int treasure_x = -3;

int trapdoor_x = 3;
int trapdoor_y = 0;

int main() {

	int active_player_number = 0;

	// Initialize both players
	Player* player1 = new Player();
	Player* player2 = new Player();
	// Initialize players (we will store the inside a vector). Initially we have two players, so we add them to our players vector
	vector<Player*> players = {player1, player2};

	// In these vectors we store all X and Y walls coordinates
	vector<int> walls_coordinates_x = {wall1_x, wall2_x};
	vector<int> walls_coordinates_y = {wall1_y, wall2_y};

	// In these vectors we store all X and Y treasure coordinates
	vector<int> treasure_coordinates_x = {treasure_x};
	vector<int> treasure_coordinates_y = {treasure_y};

	// In these vectors we store all X and Y trapdoor coordinates
	vector<int> trapdoor_coordinates_x = {trapdoor_x};
	vector<int> trapdoor_coordinates_y = {trapdoor_y};

	// Specify secret password
	char secret_password = 123;

	while (true)
	{
		// Decide which player now makes a move
		Player* active_player = players[active_player_number];

		string command = "";
		cin >> command;
		
		// Password checker
		if (command == "PSS")
		{
			check_password(active_player, secret_password, active_player_number);
		}
		// Create players command
		else if (command == "NPS")
		{
			add_players(players);
		}
		// Adding wall
		else if (command == "WLL") // TODO -> collision with walls
		{
			add_object_to_game(walls_coordinates_x, walls_coordinates_y, "wall");
		}
		// Adding treasure
		else if (command == "TRS")
		{
			add_object_to_game(treasure_coordinates_x, treasure_coordinates_y, "treasure");
		}
		// Adding trapdoor
		else if (command == "TRD")
		{
			add_object_to_game(trapdoor_coordinates_x, trapdoor_coordinates_y, "trapdoor");
		}

		// Move
		else if (command == "MOV") // TODO
		{
			move_player(players, active_player_number, 
			trapdoor_coordinates_x, trapdoor_coordinates_y,
			treasure_coordinates_x, treasure_coordinates_y,
			walls_coordinates_x, walls_coordinates_y);
		}

		// Pick a treaure
		else if (command == "PCK") // TODO
		{
			PCK_command(players, active_player_number);
		}

		// PRT option
		else if (command == "PRT")
		{
			PRT_command(players, active_player_number);
			// We don't want to switch players
			continue;
		}

		// Skip option
		else if (command == "SKP")
		{
			// Just do nothing
		}

		// End of the game command
		else if (command == "END") // TODO
		{
			if (player1->has_treasure == 'T') cout << "Player 1 won" << endl;
			else if (player2->has_treasure == 'T') cout << "Player 2 won" << endl;
			break;
		}

		// Display all available commands
		else if (command == "HLP")
		{
			print_available_commands();
			continue;
		}

		// User enter some unknown command
		else {
			print_available_commands();
			cout << "You entered unknown command, quitting the game." << endl;
			break;
		}

		// Update which player should now move
		active_player_number++;
		// Beacuse we index from 0 I have to subtract one from the size of players vector
		if (active_player_number > players.size() - 1)
		{
			// We want to make a "circle"
			active_player_number = 0;
		}
	}

	// After the end of the game we can delete all players
	for (int i = 0; i < players.size(); ++i)
	{
		delete players[i];
	}
}