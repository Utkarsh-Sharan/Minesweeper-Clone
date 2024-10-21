#pragma once

#include "Board.h"
#include <iostream>

namespace Gameplay
{
	class GameManager
	{
	private:
		Board::Board* board;
		bool game_over;
		int size;

	public:
		GameManager(int size, int mines);

		void StartGame();
	};
}