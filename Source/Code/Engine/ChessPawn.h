#pragma once

#include "ChessPiece.h"

namespace Chess
{
	class Board;

	class Pawn : public Piece
	{
	public:
		Pawn() : Piece() {};
		Pawn(Point position, Color color) : Piece(position, color) {};

		Points GetAvailableMovement(const Board& board) const override;
		void OnMoved() override;
		char GetPieceDisplay() override;

	private:
		bool isFirstMove = true;
	};
}