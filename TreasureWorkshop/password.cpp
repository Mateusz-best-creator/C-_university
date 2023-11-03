#include <iostream>
#include "player_function_definitions.h"

using namespace std;

void check_password(Player *player, char secret_password)
{
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
            if (char_bit == '1')
                bit_scanned = 1;
            else
                bit_scanned = 0;

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