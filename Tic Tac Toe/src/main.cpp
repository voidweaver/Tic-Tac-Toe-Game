#include <iostream>
#include <string>
#include <conio.h>
#include "TicTacToe.h"
#include "board.h"

#define LOG(x) std::cout << x; // For Debugging only

int main() {

	
	
	

	// getting player

	

	std::cout << std::endl;
	
	// Game Loop
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
