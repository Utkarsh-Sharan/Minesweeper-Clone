#include "Board.h"

namespace Board
{
	using namespace std;

	Board::Board(int n, int mines) : size(n), total_mines(mines), grid(n, std::vector<Cell::Cell>(n)) {}

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

	void Board::CalculateAdjacentMines()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (grid[i][j].IsMine())
					continue;

				int mines = 0;

				for (int adj_i = -1; adj_i <= 1; ++adj_i)
				{
					for (int adj_j = -1; adj_j <= 1; ++adj_j)
					{
						int a = i + adj_i, b = j + adj_j;

						//checks that cell is within board limits AND that cell is a mine, then only mines++
						if (a >= 0 && a < size && b >= 0 && b < size && grid[a][b].IsMine())
							mines++;
					}
				}
				grid[i][j].SetAdjacentMines(mines);		//setting the number we got after claculation of mines to that cell
			}
		}
		//overall complexity O(n^2) as internal 2 loops are defined. Works like O(n*n*3*3), ultimatly leading to O(n^2)
	}

	void Board::InitializeBoard(int first_input_x, int first_input_y)
	{
		PlaceMines(first_input_x, first_input_y);
		CalculateAdjacentMines();
	}

	void Board::RevealCell(int x, int y)
	{
		if (!grid[x][y].IsRevealed())
			grid[x][y].Reveal();
	}

	bool Board::IsMine(int x, int y)
	{
		return grid[x][y].IsMine();
	}

	bool Board::IsRevealed(int x, int y)
	{
		return grid[x][y].IsRevealed();
	}

	int Board::GetAdjacentMines(int x, int y)
	{
		return grid[x][y].GetAdjacentMines();
	}

	void Board::PrintBoard()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (grid[i][j].IsRevealed())
				{
					if (grid[i][j].IsMine())
						cout << "* ";
					else
						cout << grid[i][j].GetAdjacentMines() << " ";
				}
				else
				{
					cout << "# ";
				}
			}
			cout << endl;
		}
	}

	bool Board::HasWon()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (!grid[i][j].IsMine() && !grid[i][j].IsRevealed())
					return false;
			}
		}
		return true;
	}
}