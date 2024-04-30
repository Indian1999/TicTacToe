#pragma once

class GameBoard
{
    private:

        bool draw; // true for a draw game


    public:

        //constructor
        GameBoard(bool d = false)
        {
            draw = d;
        }
        void ass_draw(bool);
        //retrives value for draw
        bool get_draw();
        // change board based on move //
        void update_board(char[3][3], int, int, bool);
        // see if winner //
        bool check_for_win(char[3][3], bool);
        // see if all spaces full //
        bool check_for_draw(char[3][3]);
        // output board //
        void display_board(char[3][3]);
        // make board all spaces //
        void clear_board(char[3][3]);

        void getException();
        ~GameBoard();
};
