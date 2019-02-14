#include <iostream>
#include <string>
#include <conio.h>
#include "TicTacToe.h"
#include "board.h"

#define LOG(x) std::cout << x; // For Debugging only

int main() {

	int board_size;
	std::cout << "Please enter board size >> ";
	std::cin >> board_size;

	TicTacToe game(board_size);
	
	game.start();
	// Game Loop
	bool end = false; // don't forget to change back to true

	game.run();


	/*while (!checkwin) {
		char input;
		system("cls");
		DrawBoard();

		std::cin.get(input);
		int answer = input - '0';




		checkwin();
	}*/


	std::cin.ignore();
	return 0;
}
