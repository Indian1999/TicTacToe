#include "pch.h"
#include "../TicTacToe/GameBoard.h"
#include "../TicTacToe/Player.h"

namespace TicTacToeTest
{
	TEST(TestUpdateBoard, MoveByPerson)
	{
		GameBoard Board;
		char board[3][3] =
		{
			{'-','-','-'},
			{'-','-','-'},
			{'-','-','-'}
		};
		Board.update_board(board, 0, 0, true); // X j�t�kos
		EXPECT_EQ(board[0][0], 'X');
	}
	TEST(TestUpdateBoard, MoveByComp)
	{
		GameBoard Board;
		char board[3][3] =
		{
			{'-','-','-'},
			{'-','-','-'},
			{'-','-','-'}
		};
		Board.update_board(board, 0, 0, false); // O j�t�kos
		EXPECT_EQ(board[0][0], 'O');
	}
}