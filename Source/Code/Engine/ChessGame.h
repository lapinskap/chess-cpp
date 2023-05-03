#pragma once

#include "ChessBoard.h"
#include "ChessPlayer.h"

namespace Chess
{
	class Player;
	class Game
	{
	public:

		void SetupBoard();
		void NextMove();
		void Rollback();

	//protected:

		Board board;
		Player* players[2];
		Color currentColor = Color::White;
		std::vector<Command> history;
	};
}