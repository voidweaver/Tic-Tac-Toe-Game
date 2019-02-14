#include <iostream>
#include <string>
#include "TicTacToe.h"

bool inlimit(int since, int until, int input)
{
	return (input >= since || input <= until) ? true : false;
}

TicTacToe::TicTacToe(int board_size)
	: board_size(board_size), board_area(board_size * board_size), winner("NULL")
{
	tile = new char[board_area]; // Dynamic Allocation for the board
	for (int i = 0; i < board_area; i++) // set all tiles on the board with space
		tile[i] = (const char)((i + 1) + '0');
}

TicTacToe::~TicTacToe()
{
	delete[] tile;
}

void TicTacToe::setPlayer1_name(std::string name)
{
	player1_name = name;
}

void TicTacToe::setPlayer2_name(std::string name)
{
	player2_name = name;
}

void TicTacToe::start()
{
	std::cout << "Welcome to Tic-Tac-Toe Game(aka O-X Game) by Omsin" << std::endl << std::endl;
	
	//// round amount
	//std::cout << "Enter the amount of round(s) >> ";
	//int input;
	//while (true) {
	//	std::cin >> input;
	//	if (inlimit(1, 10, round)) {
	//		round = input;
	//		break;
	//	}
	//	else std::cout << "The amount of round must be under 1 to 10, please retry >> ";
	//}
	
	// player names
	std::cout << "Please enter the name of Player #1 >> ";
	std::string input;
	std::cin >> input;
	setPlayer1_name(input);
	std::cout << "Please enter the name of Player #2 >> ";
	std::cin >> input;
	setPlayer2_name(input);
	
}

void TicTacToe::run()
{
	while (winner == "NULL") {
		drawboard();
		std::cout << "Answer >";
		std::cin >> last_answer;
		checkwin();


	}
}

void TicTacToe::drawboard()
{
	for (int i = 0; i < board_size * 2 + 1; i++)
		std::cout << "--";
	for (int row = 0; row < board_size; row++) {
		std::cout << std::endl << "| ";
		for (int column = 0; column < board_size; column++)
			std::cout << tile[column + (3 * row)] << " | ";
		std::cout << std::endl;
	}
}

void TicTacToe::checkwin()
{
	
}

void TicTacToe::gameover()
{
	
}
