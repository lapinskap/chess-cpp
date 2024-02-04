#pragma once

#include <vector>

#include "../ChessPiece/ChessPiece.h"

namespace Chess
{
	class Board
	{
	public:

		~Board();

		void Setup();
		void Print() const;

		void AddPiece(Piece* piece);
		void RemovePiece(Piece* piece);

		Piece* GetPieceAt(Point p) const;

		bool IsValid(Point p) const;

		void Move(Point from, Point to);
		void CreateSetOfPieces(Color color);

		static const Point Size;

	private:

		std::vector<Piece*> pieces;
	};
}