#pragma once

bool inlimit(int since, int until, int input);

class TicTacToe {

private:
	int round;
	int board_size;
	char* tile;
	std::string winner;
	std::string player1_name;
	std::string player2_name;
	

public:
	TicTacToe(int board_size);
	~TicTacToe();
	
	void setPlayer1_name(std::string name);
	void setPlayer2_name(std::string name);
	
	void start();
	void checkwin();
	void gameover();


};
