#pragma once

#include "ChessPiece.h"

namespace Chess
{
	class Board;

	class King : public Piece
	{
	public:
		King() : Piece() {};
		King(Point position, Color color) : Piece(position, color) {};

		Points GetAvailableMovement(const Board& board) const override;
		char GetPieceDisplay() override;

	private:
	};
}