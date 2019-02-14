#pragma once

bool inlimit(int since, int until, int input);

class TicTacToe {

private:
	int board_size;
	int board_area;
	int last_answer;
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
	void run();
	void drawboard();
	void checkwin();
	void gameover();


};
