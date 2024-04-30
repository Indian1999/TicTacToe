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
		Board.update_board(board, 0, 0, true); // X játékos
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
		Board.update_board(board, 0, 0, false); // O játékos
		EXPECT_EQ(board[0][0], 'O');
	}

	class BoardTest : public testing::Test
	{
	protected:
		GameBoard Board;
		char board[3][3];
		void SetUp()
		{
			for (int i = 0;  i< 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					board[i][j] = '-';
				}
			}
		}
	};
	TEST_F(BoardTest, UpdateBoard_Person)
	{
		Board.update_board(board, 2, 2, true);
		EXPECT_EQ(board[2][2], 'X');
	}
	TEST_F(BoardTest, UpdateBoard_Computer)
	{
		Board.update_board(board, 2, 2, false);
		EXPECT_EQ(board[2][2], 'O');
	}
	TEST_F(BoardTest, CheckForPlayerWinHorizontal)
	{
		Board.update_board(board, 0, 0, true);
		Board.update_board(board, 0, 1, true);
		Board.update_board(board, 0, 2, true);
		EXPECT_TRUE(Board.check_for_win(board, true));
	}
	TEST_F(BoardTest, CheckForPlayerWinCross)
	{
		board[0][0] = board[1][1] = board[2][2] = 'X';
		EXPECT_TRUE(Board.check_for_win(board, true));
	}
}