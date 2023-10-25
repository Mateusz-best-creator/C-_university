#include <iostream>
#include <string>

// Upload our functions
// future :)

using namespace std;

struct Player
{
	int x_coordinate = 0;
	int y_coordinate = 0;
	char entered = 'F';
	bool stands_on_the_treasure = false;
	char has_treasure = 'F';
	char won_game = 'F';
	char lost = 'F';
};

void check_password(Player* player, char secret_password, int& which_player);
void move_player(Player* player, int active_player_number);
void PCK_command(Player* player1, Player* player2, int active_player_number);
void print_available_commands();
void print_info(Player* player, int active_player_number);
void PRT_command(Player* player1, Player* player2, int& active_plater_number);

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

	int active_player_number = 1;

	// Initialize both players
	Player* player1 = new Player();
	Player* player2 = new Player();

	// Specify secret password
	char secret_password = 123;

	while (true)
	{
		string command = "";
		cin >> command;
		
		// Password checker
		if (command == "PSS")
		{
			if (active_player_number == 1)
			{
				check_password(player1, secret_password, active_player_number);
			}
			else
			{
				check_password(player2, secret_password, active_player_number);
			}
		}

		// Move
		else if (command == "MOV")
		{
			bool end_of_the_game = false;
			if (active_player_number) move_player(player1, active_player_number);
			else move_player(player2, active_player_number);
	
		}

		// Pick a treaure
		else if (command == "PCK")
		{
			PCK_command(player1, player2, active_player_number);
		}

		// PRT option
		else if (command == "PRT")
		{
			PRT_command(player1, player2, active_player_number);
			// We don't want to switch players
			continue;
		}

		// Skip option
		else if (command == "SKP")
		{
			// Just do nothing
		}

		// End of the game command
		else if (command == "END")
		{
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
		active_player_number = (active_player_number + 1) % 2;
	}

	// After the end of the game we can delete both players
	delete player1, player2;

	return 0;
}

void check_password(Player* player, char secret_password, int& which_player)
{
	char guessed_password[8];
	// Check if the player arleady guessed password
	if (player->entered == 'T')
	{
		cout << "Player 1 arleady guessed password." << endl;
	}
	else
	{	
		bool password_guessed = true;
		for (int i = 0; i < 8; ++i)
		{
			char char_bit;
			cin >> char_bit;
			int bit_scanned;
			if (char_bit == '1') bit_scanned = 1;
			else bit_scanned = 0;

			char flag = 1 << (7 - i);
			char PasswordAtPosition = secret_password & flag;
			char PasswordBitAtPosition = PasswordAtPosition >> (7 - i);
			if (PasswordBitAtPosition != bit_scanned)
			{
				password_guessed = false;
			}
		}
		
		// check if use provided appropriate password
		if (password_guessed)
		{
			cout << "PASSWORD GUESSED" << endl;
			player->entered = 'T';
		}
		else
		{
			cout << "PASSWORD NOT GUESSED" << endl;
		}
	}
}

void move_player(Player* player, int active_player_number)
{
	char direction;
	cin >> direction;

	switch (direction)
	{
	case 'N':
		player->x_coordinate -= 1;
		break;
	case 'E':
		player->y_coordinate += 1;
		break;
	case 'S':
		player->x_coordinate += 1;
		break;
	case 'W':
		player->y_coordinate -= 1;
		break;
	default:
		cout << "Wrong direction." << endl;
		break;
	}

	int current_x_coordinate = player->x_coordinate;
	int current_y_coordinate = player->y_coordinate;

	if ((current_x_coordinate + 1 == trapdoor_x && current_y_coordinate == trapdoor_y
		|| current_x_coordinate - 1 == trapdoor_x && current_y_coordinate == trapdoor_y
		|| current_x_coordinate == trapdoor_x && current_y_coordinate + 1 == trapdoor_y
		|| current_x_coordinate == trapdoor_x && current_y_coordinate - 1 == trapdoor_y))
	{
		cout << "You see a trapdoor at (" << trapdoor_x << "," << trapdoor_y << ")" << endl;
	}
	if (current_x_coordinate + 1 == treasure_x && current_y_coordinate == treasure_y
		|| current_x_coordinate - 1 == treasure_x && current_y_coordinate == treasure_y
		|| current_x_coordinate == treasure_x && current_y_coordinate + 1 == treasure_y
		|| current_x_coordinate == treasure_x && current_y_coordinate - 1 == treasure_y
		|| current_x_coordinate == treasure_x && current_y_coordinate == treasure_y)
	{
		cout << "You see a treasure at (" << treasure_x << "," << treasure_y << ")" << endl;
	}

	// Check of player entered a trapdoor
	if (player->x_coordinate == trapdoor_x && player->y_coordinate == trapdoor_y)
	{
		if (active_player_number == 0) active_player_number = 2;
		cout << "Player " << active_player_number << " lost" << endl;
		player->lost = true;
	}

	// Check if player found the treasure
	if (player->x_coordinate == treasure_x && player->y_coordinate == treasure_y)
	{
		player->stands_on_the_treasure = true;
	}
	else {
		player->stands_on_the_treasure = false;
	}
}

void PCK_command(Player* player1, Player* player2, int active_player_number)
{
	if (active_player_number == 1)
	{
		if (player1->stands_on_the_treasure)
		{
			player1->has_treasure = 'T';
		}
	}
	else
	{
		if (player2->stands_on_the_treasure)
		{
			player2->has_treasure = 'T';
		}
	}
}

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

void print_info(Player* player, int active_player_number)
{
	if (active_player_number == 0) active_player_number = 2;
	cout << "Active Player: " << active_player_number << " ";
	cout << "Coordinates: " << player->x_coordinate << ", " << player->y_coordinate << " ";
	cout << "Entered: " << player->entered << " " << "Lost: " << player->lost << " ";
	cout << "Has Treasure: " << player->has_treasure << " " << "Won Game: " << player->won_game << endl;
}


void PRT_command(Player* player1, Player* player2, int& active_player_number)
{
	char x;
	cin >> x;
	if (x == '0' || x == '-')
	{
		if (active_player_number == 1) print_info(player1, active_player_number);
		else print_info(player2, active_player_number);
	}
	else if (x == '1')
	{
		print_info(player1, active_player_number);
		print_info(player2, active_player_number);
	}
}
