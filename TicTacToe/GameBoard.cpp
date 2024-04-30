#include <cstdlib>
#include <iostream>
#include "GameBoard.h"

using namespace std;

//resets board to all - for a clean playing area.

void GameBoard::clear_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = '-';
    }
}


//assigns X or O depending on whos turn and what row/col they picked

void GameBoard::update_board(char board[3][3], int row, int col, bool person_next)
{
    if (row >= 3 || col >= 3)
    {
        throw std::out_of_range("Invalid input");
    }


    cout << endl;

    if (person_next == true)
        board[row][col] = 'X';
    else
        board[row][col] = 'O';
}


//displays current board

void GameBoard::display_board(char board[3][3])
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << board[i][j];
        cout << endl;
    }
}



//checks for a win by checking through each possible win state

bool GameBoard::check_for_win(char board[3][3], bool person_next)
{
    if (person_next == true)
    {
        //  X   X   X           -   -   -           -   -   -
        //  -   -   -           X   X   X           -   -   -
        //  -   -   -           -   -   -           X   X   X

        if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
            return true;
        if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
            return true;
        if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
            return true;

        //  X   -   -           -   X   -           -   -   X
        //  X   -   -           -   X   -           -   -   X
        //  X   -   -           -   X   -           -   -   X

        if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
            return true;
        if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
            return true;
        if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
            return true;


        //  X   -   -           -   -   X           
        //  -   X   -           -   X   -           
        //  -   -   X           X   -   -

        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
            return true;
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
            return true;
        else
            return false;
    }

    if (person_next == false)
    {
        if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
            return true;
        if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
            return true;
        if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
            return true;

        if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
            return true;
        if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
            return true;
        if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
            return true;

        if (board[0][0] == 'O' && board[0][1] == 'O' && board[2][2] == 'O')
            return true;
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
            return true;
        else
            return false;
    }
}


//checks for a draw by checking each place for being unoccupied

bool GameBoard::check_for_draw(char board[3][3])
{
    if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' &&
        board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' &&
        board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-')
        return true;
    else
        return false;
}


//gets draw member data

bool GameBoard::get_draw()
{
    return draw;
}


void GameBoard::getException()
{
    throw "EXCEPTION";
}

//assigns value to draw member data

void GameBoard::ass_draw(bool d)
{
    draw = d;
}


//GameBoard deconstructor   

GameBoard::~GameBoard()
{
}