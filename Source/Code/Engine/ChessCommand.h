#pragma once

#include "ChessPoint.h"

namespace Chess
{
	class Board;
	class Piece;

	struct Command
	{
		Command() = default;
		Command(Point f, Point t) : from(f), to(t) {}
		~Command();
		Command(Command&& other);
		void operator == (Command&& other);
		Command(const Command& other) = delete;
		void operator = (const Command& other) = delete;

		bool IsValid(const Board& board) const;
		void Do(Board& board);
		void Undo(Board& board);

		Point from;
		Point to;
		//Piece* capturedPiece = nullptr;
		PieceType capturedPieceType = PieceType::None;
	};
}