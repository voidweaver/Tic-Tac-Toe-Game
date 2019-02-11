#include <iostream>
#include <string>
#include "TicTacToe.h"

bool inlimit(int since, int until, int input)
{
	return (input >= since || input <= until) ? true : false;
}

TicTacToe::TicTacToe(int board_size)
	: board_size(board_size)
{
	tile = new char[board_size]; // Dynamic Allocation for the board
	for (int i = 0; i < board_size; i++) // set all tiles on the board with space
		tile[i] = (char)" ";
	round = 0; // first round is round 1 but start with 0 in the program
}

TicTacToe::~TicTacToe()
{
}

void setPlayer1_name(std::string name)
{
	player1_name = name;
}

void setPlayer2_name(std::string name)
{
	player2_name = name;
}

void start()
{
	std::cout << "Welcome to Tic-Tac-Toe Game(aka O-X Game) by Omsin" << std::endl << std::endl;
	
	// round amount
	std::cout << "Enter the amount of round(s) >> ";
	int input;
	while (true) {
		std::cin >> input;
		if (inlimit(1, 10, round))
			round = input;
			break;
		else std::cout << "The amount of round must be under 1 to 10, please retry >> ";
	}
	
	// player names
	std::cout << "Please enter the name of Player #1 >> ";
	std::string input;
	cin >> input;
	setPlayer1_name(input);
	std::cout << "Please enter the name of Player #2 >> ";
	cin >> input;
	setPlayer2_name(input);
	
}

void checkwin()
{
	
}

void gameover()
{
	
}
