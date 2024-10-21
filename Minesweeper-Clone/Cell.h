#pragma once

namespace Cell
{
	class Cell
	{
	private:
		bool is_mine;			//cell's a mine?
		bool is_revealed;		//cell's revealed?
		int adjacent_mines;		//number of adj mines to this cell.

	public:
		Cell() : is_mine(false), is_revealed(false), adjacent_mines(0) {}	//initializer list

		void PlaceMine();

		bool IsMine();
		bool IsRevealed();

		void Reveal();

		int GetAdjacentMines();
		void SetAdjacentMines(int mine_count);
	};
}