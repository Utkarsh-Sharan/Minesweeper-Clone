#include "Board.h"

namespace Board
{
	void Board::PlaceMines(int first_input_x, int first_input_y)
	{
		srand(time(0));
		int mines_placed = 0;

		while (mines_placed < total_mines)
		{
			int x = rand() % size;
			int y = rand() % size;

			if (x == first_input_x && y == first_input_y)
				continue;

			if (!grid[x][y].IsMine())
			{
				grid[x][y].PlaceMine();
				mines_placed++;
			}
		}
	}
}