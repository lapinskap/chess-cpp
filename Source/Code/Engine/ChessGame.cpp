#include "ChessGame.h"
#include "ChessPlayer.h"

void Chess::Game::SetupBoard() 
{ 
	board.Setup(); 
}

void Chess::Game::NextMove()
{
	Command cmd = players[(int)currentColor]->MakeMove(*this);
	if (cmd.IsValid(board))
	{
		cmd.Do(board);
		history.push_back(std::move(cmd));
		currentColor = (Color)(!(int)currentColor);
	}
}

void Chess::Game::Rollback()
{
	if (history.empty())
		return;

	history.back().Undo(board);
	history.pop_back();
}