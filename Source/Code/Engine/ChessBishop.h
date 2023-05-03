#pragma once

#include "ChessPiece.h"

namespace Chess
{
	class Board;

	class Bishop : public Piece
	{
	public:
		Bishop() : Piece() {};
		Bishop(Point position, Color color) : Piece(position, color) {};

		Points GetAvailableMovement(const Board& board) const override;
		char GetPieceDisplay() override;

	private:
	};
}