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
		// const override ?? TODO
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
	};

	class PawnMovement : public PieceMovement
	{
	public:
		~PawnMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const = 0;
	};

	class BishopMovement : public PieceMovement
	{
	public:
		~BishopMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const = 0;
	};

	class QueenMovement : public PieceMovement
	{
	public:
		~QueenMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const = 0;
	};

	class KingMovement : public PieceMovement
	{
	public:
		~KingMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const = 0;
	};
}