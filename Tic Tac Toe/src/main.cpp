#include <iostream>
#include <string>
#include "TicTacToe.h"
#include "board.h"

#define LOG(x) std::cout << x; // For Debugging only

int main() {

	for (int i = 0; i < 80; i++)
		std::cout << "-";
	std::cout << "Copyright 2019 Krissada Singhakachain.  All rights reserved." << std::endl;
	for (int i = 0; i < 80; i++)
		std::cout << "-";
	std::cout << std::endl;

	std::cout << "Welcome to Tic-Tac-Toe Game(aka O-X Game) by Omsin" << std::endl << std::endl;

	int board_width;
	std::cout << "Please enter board width >> ";
	std::cin >> board_width;

	TicTacToe game(board_width);
	
	game.start();
	game.run();
	game.summary();


	/*while (!checkwin) {
		char input;
		system("cls");
		DrawBoard();

		std::cin.get(input);
		int answer = input - '0';




		checkwin();
	}*/


	system("pause");
	return 0;
}
