#pragma once

#include "ChessPiece.h"

namespace Chess
{
	class Board;

	class Queen : public Piece
	{
	public:
		Queen() : Piece() {};
		Queen(Point position, Color color) : Piece(position, color) {};

		Points GetAvailableMovement(const Board& board) const override;
		char GetPieceDisplay() override;

	private:
	};
}