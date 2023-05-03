#pragma once

#include "../ChessPoint/ChessPoint.h"
#include "../ChessDefinitions.h"
#include "../ChessPieceMovement/ChessPieceMovement.h"

namespace Chess
{
	class Board;

	class Piece
	{
	public:

		Piece() = default;
		//Piece(PieceType type);
		Piece(PieceType type, Color color, Point position);
		~Piece();

		Point GetPosition() const;
		void SetPosition(Point pos);

		Color GetColor() const;
		void SetColor(Color color);

		PieceType GetType() const;

		virtual Points GetAvailableMovement(const Board& board) const;

	private:

		PieceType type = PieceType::Pawn;
		Point position;
		Color color = Color::White;
		PieceMovement* pieceMovement = nullptr;
	};
}