#pragma once

#include "ChessPiece.h"

namespace Chess
{
	class Board;

	class Knight : public Piece
	{
		public:
		Knight() : Piece() {};
		Knight(Point position, Color color) : Piece(position, color) {};

		Points GetAvailableMovement(const Board& board) const override;
		char GetPieceDisplay() override;

		private:
	};
}