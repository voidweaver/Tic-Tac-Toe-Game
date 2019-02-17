#pragma once

bool inlimit(int since, int until, int input);

class TicTacToe {

private:
	int board_width;
	int board_area;
	int round;
	int last_answer;
	int currentrow;
	int currentcolumn;
	int** tile_display;
	char** tile_raw;
	bool hide;
	bool end;
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
	void summary();


};
