#include "board.h"
#include <iostream>

void DrawWall()
{
	for (int i = 0; i < 80; i++)
		std::cout << "-";
}

inline void DrawBoard() {
	int input;
	DrawWall();
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			std::cout << "  |" << input;
		}
		std::cout << std::endl;
	}
	DrawWall();
}

void checkwin()
{
	
}

void DrawSummary()
{
}
