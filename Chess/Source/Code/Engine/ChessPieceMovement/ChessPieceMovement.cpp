#include "ChessPieceMovement.h"
#include "../ChessBoard/ChessBoard.h"

bool IsAddPointPossible(Chess::Point to, Chess::Color pieceColor, const Chess::Board& board)
{
	if (!board.IsValid(to))
	{
		return false;
	}

	if (Chess::Piece* piece = board.GetPieceAt(to))
	{
		if (piece->GetColor() == pieceColor)
		{
			return false;
		}

		return false;
	}

	return true;
}


Chess::Points Chess::KnightMovement::GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const
{
	Chess::Points points;

	Chess::Points knightMovements =
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
		if (IsAddPointPossible(point, color, board))
			points.push_back(point);
	}

	return points;

}

Chess::Points Chess::RookMovement::GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const
{
	Chess::Points points;

	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(0, i), color, board))
		{
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(0, -i), color, board))
		{
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(i, 0), color, board))
		{
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(-i, 0), color, board))
		{
			break;
		}
	}
	return points;
}

Chess::Points Chess::BishopMovement::GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const
{
	Chess::Points points;

	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(i, i), color, board))
		{
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(-i, i), color, board))
		{
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(i, -i), color, board))
		{
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		if (IsAddPointPossible(from + Point(-i, -i), color, board))
		{
			break;
		}
	}

	return points;
}

Chess::Points Chess::KingMovement::GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const
{
	QueenMovement queenMovement;

	Points kingPoints = queenMovement.GetAvailableMovement(from, color, board, 1);

	return kingPoints;
}


Chess::Piece::~Piece()
{
	delete pieceMovement;
}
