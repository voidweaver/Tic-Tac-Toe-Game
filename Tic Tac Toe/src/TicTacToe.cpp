#include <iostream>
#include "TicTacToe.h"

TicTacToe::TicTacToe(int board_size)
	:board_size(board_size)
{
	board = new char[board_size];
	for (int i = 0; i < board_size; i++)
		board[i] = (char)" ";
	round = 0; // first round is round 1 but start with 0 in the program
}

TicTacToe::~TicTacToe()
{
}
