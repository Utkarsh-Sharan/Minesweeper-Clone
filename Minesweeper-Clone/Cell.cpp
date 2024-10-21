#include "Cell.h"

namespace Cell
{
	void Cell::PlaceMine()
	{
		is_mine = true;
	}

	void Cell::Reveal()
	{
		is_revealed = true;
	}

	bool Cell::IsMine()
	{
		return is_mine;
	}

	bool Cell::IsRevealed()
	{
		return is_revealed;
	}

	int Cell::GetAdjacentMines()
	{
		return adjacent_mines;
	}

	void Cell::SetAdjacentMines(int mine_count)
	{
		adjacent_mines = mine_count;
	}
}