#include "GameManager.h"

namespace Gameplay
{
	using namespace std;

	GameManager::GameManager(int size, int mines)
	{
		board = new Board::Board(size, mines);
		game_over = false;
		this->size = size;
	}

	void GameManager::StartGame()
	{
		int first_input_x, first_input_y;

		cout << "Enter your first move (x y): " << endl;
		cin >> first_input_x >> first_input_y;

		if (first_input_x >= size || first_input_y >= size)
		{
			cout << "DO.. NOT.. Enter invalid number! Game over!" << endl;
			game_over = true;
			return;
		}

		board->InitializeBoard(first_input_x, first_input_y);
		board->RevealCell(first_input_x, first_input_y);

		while (!game_over)
		{
			board->PrintBoard();
			if (board->HasWon())
			{
				cout << "Congratulations! You Won!" << endl << "See you again!" << endl;
				board->PrintBoard();
				break;
			}

			int x, y;
			cout << "Enter your next move (x y): " << endl;
			cin >> x >> y;

			if (x >= size || y >= size)
			{
				cout << "DO.. NOT.. Enter invalid number! Game over!" << endl;
				game_over = true;
				break;
			}

			if (board->IsMine(x, y))
			{
				cout << "Haa!! stepped on a mine! Game over." << endl;
				game_over = true;
				board->RevealCell(x, y);
				board->PrintBoard();
			}
			else
				board->RevealCell(x, y);
		}
	}
}