#pragma once

#include "Cell.h"
#include <vector>
#include <cstdlib>   //random access
#include <ctime>     //time based seed value
#include <iostream>

namespace Board
{
	class Board
	{
	private:
		int size;
		int total_mines;
		std::vector<std::vector<Cell::Cell>> grid;

		void PlaceMines(int first_input_x, int first_input_y);
		void CalculateAdjacentMines();

	public:
		Board(int n, int mines);

		void InitializeBoard(int first_input_x, int first_input_y);
		void RevealCell(int x, int y);

		bool IsMine(int x, int y);
		bool IsRevealed(int x, int y);

		int GetAdjacentMines(int x, int y);

		void PrintBoard();
		bool HasWon();
	};
}