#pragma once

class Player
{
    private:

    public:
        // true if human first //
        bool goFirst();
        // ask person for move, validate //
        void get_person_move(char[3][3], int&, int&);
        // get computer move //
        void get_computer_move(char[3][3], int&, int&);
        ~Player();
};