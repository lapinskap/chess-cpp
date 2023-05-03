#include "ChessPieceMovement.h"
#include "../ChessBoard/ChessBoard.h"

bool IsAddPointPossible(Chess::Point to, Chess::Color pieceColor, const Chess::Board& board, Chess::Points& points)
{
	if (board.IsValid(to))
	{
		return false;
	}

	if (Chess::Piece* piece = board.GetPieceAt(to))
	{
		if (piece->GetColor() == pieceColor)
		{
			return false;
		}

		//points.push_back(to);
		return false;
	}

	//points.push_back(to);
	return true;
}


Chess::Points Chess::KnightMovement::GetAvailableMovement(Point from, Color color, const Board& board) const
{
	Chess::Points points;

	Chess::Points knightMovements
	{
		Point(from.x + 2, from.y - 1),
		Point(from.x + 2, from.y + 1),
		Point(from.x + 1, from.y - 2),
		Point(from.x + 1, from.y + 2),
		Point(from.x - 1, from.y - 2),
		Point(from.x - 1, from.y + 2),
		Point(from.x - 2, from.y - 1),
		Point(from.x - 2, from.y + 1),
	};

	for (Point point : knightMovements)
	{
		if (IsAddPointPossible(point, color, board, points))
		{
			points.push_back(point);
		}
	}

	return points;

}

Chess::Piece::~Piece()
{
	delete pieceMovement;
}
