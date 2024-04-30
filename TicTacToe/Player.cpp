#include <cstdlib>
#include <iostream>
#include "Player.h"

using namespace std;

//determines who will go first

bool Player::goFirst()
{
    char answer;
    do
    {
        cout << "Do you want to go first? Y/N" << endl;
        cin >> answer;
        if (answer == 'y' or answer == 'Y')
            return true;
        if (answer == 'n' or answer == 'N')
            return false;
    } while (answer != 'Y' && answer != 'y' && answer != 'n' && answer != 'N');
}


//get players move

void Player::get_person_move(char board[3][3], int& row, int& col)
{

    bool repeat = true;
    do
    {
        do
        {
            cout << "enter the cordinats as to where you want to go." << endl;
            cout << "Row 0-2 and column 0-2: " << endl;
            cout << "Row: " << endl;
            cin >> row;
            cout << "Column: " << endl;
            cin >> col;
        } while (row < -1 && row > 3 && col < -1 && col > 3);

        if (board[row][col] != '-')
            cout << "That place is already taken." << endl;
        else
            repeat = false;
    } while (repeat == true);
}


//gets computers move by generating a random number for row and col
//and checking to see if that space is available.

void Player::get_computer_move(char board[3][3], int& row, int& col)
{
    do
    {
        row = (rand() % 3);
        col = (rand() % 3);
    } while (board[row][col] != '-');
}


//deconstructor
Player::~Player()
{
}

