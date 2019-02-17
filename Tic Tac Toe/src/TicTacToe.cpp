#include <iostream>
#include <string>
#include <iomanip>
#include "TicTacToe.h"

bool inlimit(int since, int until, int input)
{
	return (input >= since || input <= until) ? true : false;
}

void toggle(bool& boolean)
{
	if (boolean)
		boolean = false;
	else boolean = true;
}

TicTacToe::TicTacToe(int board_width)
	: board_width(board_width), board_area(board_width * board_width), end(false), round(1), hide(false)
{
	tile_display = new int*[board_width]; // Dynamic Allocation for the board
	for (int row = 0; row < board_width; row++)
		tile_display[row] = new int[board_width];

	for (int row = 0; row < board_width; row++)
		for (int column = 0; column < board_width; column++)// set all tiles on the board with numbers
			tile_display[row][column] = column + row * board_width + 1;

	tile_raw = new char*[board_width]; // Dynamic Allocation for the board
	for (int row = 0; row < board_width; row++)
		tile_raw[row] = new char[board_width];

	for (int row = 0; row < board_width; row++)
		for (int column = 0; column < board_width; column++)// set all tiles on the board with numbers
			tile_raw[row][column] = '\0';
}

TicTacToe::~TicTacToe()
{
	for (int i = 0; i < board_width; i++)
		delete[] tile_display[i];
	delete[] tile_display;
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
	while (!end) {
		drawboard();
		std::cout << "Answer >";
		std::cin >> last_answer;
		if (last_answer == 0) {
			toggle(hide);
			system("cls");
			continue;
		}
		currentrow = (last_answer - 1) / board_width;
		currentcolumn = (last_answer - 1) % board_width;
		if (tile_raw[(last_answer - 1) / board_width][(last_answer - 1) % board_width] == '\0') {
			tile_raw[(last_answer - 1) / board_width][(last_answer - 1) % board_width] = (round % 2 ? 'O' : 'X');
			round++;
		}
		else {
			while ((tile_raw[(last_answer - 1) / board_width][(last_answer - 1) % board_width] != '\0' && last_answer != 0) || !inlimit(0, board_area, last_answer)) {
				std::cout << "Tile already reserved or answer out of length, please try again >>";
				std::cin >> last_answer;
				currentrow = (last_answer - 1) / board_width;
				currentcolumn = (last_answer - 1) % board_width;

			}
			tile_raw[(last_answer - 1) / board_width][(last_answer - 1) % board_width] = (round % 2 ? 'O' : 'X');
			round++;
		}

		checkwin();
		system("cls");


	}
}

void TicTacToe::drawboard()
{
	std::cout << "O : " << player1_name << std::endl << "X : " << player2_name << std::endl << std::endl;
	std::cout << "Current turn : " << (round % 2 ? player1_name : player2_name) << std::endl << std::endl;

	for (int i = 0; i < board_width * 6 + 1; i++)
		std::cout << "-";
	for (int row = 0; row < board_width; row++) {
		std::cout << std::endl << "| ";
		for (int column = 0; column < board_width; column++) {
			if (tile_raw[row][column] == 0)
				std::cout << std::setw(3) << (hide ? (std::string)" " : std::to_string(tile_display[row][column]));
			else
				std::cout << " " << tile_raw[row][column] << " ";
			std::cout << " | ";
		}

		std::cout << std::endl;
	}
	for (int i = 0; i < board_width * 6 + 1; i++)
		std::cout << "-";
	std::cout << std::endl << std::endl;
}

void TicTacToe::checkwin()
{
	bool havewin = false;
	int th = 0, tv = 0, td = 0;
	for (int i = 0; i < board_width && !havewin; i++) { // For player 1
		for (int j = 0; j < board_width && !havewin; j++) {

			if (tile_raw[i][j] != 'O') { // Horizontal
				th = 0;
			}
			else if (th == board_width - 1) {
				havewin = true;
				winner = player1_name;
				end = true;
			}
			else th++;

			if (tile_raw[j][i] != 'O') { // Vertical
				tv = 0;
			}
			else if (tv == board_width - 1) {
				havewin = true;
				winner = player1_name;
				end = true;
			}
			else tv++;



		}
		if (tile_raw[i][i] != 'O') { // Diagonal
			td = 0;
		}
		else if (td == board_width - 1) {
			havewin = true;
			winner = player1_name;
			end = true;
		}
		else td++;
	}

	for (int i = 0; i < board_width && !havewin; i++) { // For player 2
		for (int j = 0; j < board_width && !havewin; j++) {

			if (tile_raw[i][j] != 'X') { // Horizontal
				th = 0;
			}
			else if (th == board_width - 1) {
				havewin = true;
				winner = player2_name;
				end = true;
			}
			else th++;

			if (tile_raw[j][i] != 'X') { // Vertical
				tv = 0;
			}
			else if (tv == board_width - 1) {
				havewin = true;
				winner = player2_name;
				end = true;
			}
			else tv++;



		}
		if (tile_raw[i][i] != 'X') { // Diagonal
			td = 0;
		}
		else if (td == board_width - 1) {
			havewin = true;
			winner = player2_name;
			end = true;
		}
		else td++;
	}
}

void TicTacToe::summary()
{
	if (winner != "NULL") {
		std::cout << "Winner : " << winner << " !";
	}
	else {
		std::cout << "DRAW !";
	}
}
