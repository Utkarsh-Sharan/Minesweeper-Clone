#include "GameManager.h"
#include <iostream>

using namespace std;

void PrintWelcomeMessage() 
{
    cout << "=====================================" << endl;
    cout << "          Welcome to Minesweeper!     " << endl;
    cout << "=====================================" << endl;
    cout << "Rules of the Game:" << endl;
    cout << "1. The board is of size 4*4, and is divided into cells, with mines hidden under some." << endl;
    cout << "2. Your goal is to open all cells without hitting a mine." << endl;
    cout << "3. The first cell you click is guaranteed to be safe." << endl;
    cout << "4. Numbers show how many mines are adjacent to that cell." << endl;
    cout << "5. This game uses 0-based indexing for rows and columns." << endl;
    cout << "6. Be careful! Entering numbers out of bounds will end the game." << endl;
    cout << "7. Good luck and have fun!" << endl;
    cout << "=====================================" << endl;
}

int main()
{
	int size = 4;
	int mines = 5;

	Gameplay::GameManager* game_manager = new Gameplay::GameManager(size, mines);

    PrintWelcomeMessage();
	game_manager->StartGame();

	return 0;
}