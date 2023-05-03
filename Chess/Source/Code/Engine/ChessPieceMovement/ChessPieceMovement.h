#pragma once
#include "../ChessPoint/ChessPoint.h"
#include "../ChessDefinitions.h"

namespace Chess
{
	class Board;

	class PieceMovement
	{
	public:
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board) const = 0;
	};


	class KnightMovement: public PieceMovement 
	{
	public:
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board) const override;
	};


}