#pragma once
#include "../ChessPoint/ChessPoint.h"
#include "../ChessDefinitions.h"

namespace Chess
{
	class Board;

	class PieceMovement
	{
	public:
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const = 0;
	};


	class KnightMovement : public PieceMovement 
	{
	public:
		~KnightMovement() = default;
		Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
		// const override ?? TODO
		//virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
	};

	class PawnMovement : public PieceMovement
	{
	public:
		~PawnMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
	};

	class RookMovement : public PieceMovement
	{
	public:
		~RookMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
	};

	class BishopMovement : public PieceMovement
	{
	public:
		~BishopMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
	};

	class QueenMovement : public PieceMovement
	{
	public:
		~QueenMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
	};

	class KingMovement : public PieceMovement
	{
	public:
		~KingMovement() = default;
		virtual Points GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const override;
	};
}