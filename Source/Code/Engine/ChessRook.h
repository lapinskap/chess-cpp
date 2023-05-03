#pragma once

#include "ChessPiece.h"

namespace Chess
{
	class Board;

	class Rook : public Piece
	{
	public:
		Rook() : Piece() {};
		Rook(Point position, Color color) : Piece(position, color) {};

		Points GetAvailableMovement(const Board& board) const override;
		char GetPieceDisplay() override;

	private:
	};
}