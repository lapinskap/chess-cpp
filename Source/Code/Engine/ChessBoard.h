#pragma once

#include <vector>
#include "ChessPoint.h"
#include "ChessPiece.h"

namespace Chess
{
	class Board
	{
	public:

		static const int BOARD_CELL_X = 8;
		static const int BOARD_CELL_Y = 8;

		~Board();

		Piece* GetPieceAt(Point p) const;

		bool IsValid(Point p) const;
		bool IsValidMovement(Piece* piece, Point to) const;

		void Setup();
		void Print() const;

		void AddPiece(Piece* piece);
		void RemovePiece(Piece* piece);

		void Move(Point from, Point to);
		void DisplayAvaliableMove(Piece* piece);
		void SetupPieces(Color color, int y);

	private:

		std::vector<Piece*> pieces;
	};
}
