#pragma once

#include "Cell.h"
#include <vector>
#include <cstdlib>   //random access
#include <ctime>     //time based seed value

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

	};
}