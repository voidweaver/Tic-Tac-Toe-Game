#include <iostream>
#include <string>
#include <conio.h>
#include "TicTacToe.h"
#include "board.h"

#define LOG(x) std::cout << x;

int main() {

	std::cout << "Welcome to Tic-Tac-Toe Game(aka O-X Game) by Omsin" << std::endl << std::endl;
	
	// round amount
	int roundAmount;
	std::cout << "Enter the amount of round(s) >> ";
	while (true) {
		std::cin >> roundAmount;
		if (roundAmount > 100 || roundAmount < 1) {
			std::cout << "The amount of round must be under 1 to 100, please retry >> ";
		}
		else break;
	}

	// getting player
	Player player1, player2;

	std::cout << "Enter the name of Player #1 >> ";
	std::string* input = new std::string;
	std::cin >> *input;
	player1.SetName(*input);
	
	std::cout << "Enter the name of Player #2 >> ";
	std::cin >> *input;
	player2.SetName(*input);
	delete input;

	std::cout << std::endl;
	
	
	bool shouldEnd = false; // don't forget to change back to true


	for (int game = 1; game <= roundAmount; game++) {
		char input;
		system("cls");
		DrawBoard();

		std::cin.get(input);
		int answer = input - '0';




		checkwin();
	}


	std::cin.ignore();
	return 0;
}