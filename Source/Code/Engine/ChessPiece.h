#pragma once

#include "ChessPoint.h"
#include "ChessDefinitions.h"

namespace Chess
{
	class Board;

	class Piece
	{
	public:

		Piece() = default;
		Piece(Point pos, Color color);
		virtual ~Piece();

		Point GetPosition() const;
		void SetPosition(Point pos);

		Color GetColor() const;

		virtual Points GetAvailableMovement(const Board& board) const = 0;
		virtual char GetPieceDisplay() = 0;
		virtual void OnMoved() { }

	protected:
		bool AddPoint(Point point, Color color, const Board& board, Points& points) const;


	private:
		Point position;
		Color color = Color::White;

		void SetColor(Color color_);
	};
}
