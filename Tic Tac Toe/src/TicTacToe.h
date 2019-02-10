#pragma once

class TicTacToe {

private:
	int round;
	std::string winner;
	std::string player1_name;
	std::string player2_name;
	int board_size;
	char* board;

public:
	TicTacToe(int board_size);
	~TicTacToe();
	void start();


};