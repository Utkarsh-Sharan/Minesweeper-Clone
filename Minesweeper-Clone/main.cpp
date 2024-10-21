#include "GameManager.h"

int main()
{
	int size = 3;
	int mines = 4;

	Gameplay::GameManager* game_manager = new Gameplay::GameManager(size, mines);
	game_manager->StartGame();

	return 0;
}