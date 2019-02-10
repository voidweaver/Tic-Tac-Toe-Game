#pragma once

class TicTacToe {

private:
	std::string player_name;
	std::string winner;
	int size;
	int* board;

public:
	TicTacToe(int board_size);
	~TicTacToe();

};