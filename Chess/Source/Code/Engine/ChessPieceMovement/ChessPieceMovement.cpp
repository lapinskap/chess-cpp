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
		const Point point = from + Point(0, i);
		if (IsAddPointPossible(point, color, board))
		{	
			points.push_back(from + point);
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		const Point point = from + Point(0, -i);
		if (IsAddPointPossible(point, color, board))
		{
			points.push_back(point);
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		const Point point = from + Point(i, 0);
		if (IsAddPointPossible(point, color, board))
		{
			points.push_back(point);
			break;
		}
	}
	for (int i = 1; i <= maxRadius; i++)
	{
		const Point point = from + Point(-i, 0);
		if (IsAddPointPossible(point, color, board))
		{
			points.push_back(point);
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

Chess::Points Chess::QueenMovement::GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const
{
	Chess::RookMovement rookMovement;
	Chess::BishopMovement bishopMovement;
	// Chess::BishopMovement* bishopMovement = new BishopMovement(from, color, board, maxRadius);

	Points rookPoints = rookMovement.GetAvailableMovement(from, color, board, maxRadius);
	Points bishopPoints = bishopMovement.GetAvailableMovement(from, color, board, maxRadius);

	Points queenPoints = rookPoints;
	queenPoints.insert(rookPoints.end(), bishopPoints.begin(), bishopPoints.end());

	return queenPoints;
}

Chess::Points Chess::KingMovement::GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const
{
	QueenMovement queenMovement;

	Points kingPoints = queenMovement.GetAvailableMovement(from, color, board, 1);

	return kingPoints;
}

Chess::Points Chess::PawnMovement::GetAvailableMovement(Point from, Color color, const Board& board, int maxRadius) const
{

	Points pawnPoints;

	auto addIfPossible = [&](Point point) {
		if (IsAddPointPossible(point, color, board))
		{
			pawnPoints.push_back(point);
			return true;
		}
		return false;
	};

	if (color == Color::White)
	{
		if (addIfPossible(from + Point(0, 1)) && from.y == 1)
			addIfPossible(from + Point(0, 2));
	}
	else
	{
		if (addIfPossible(from + Point(0, -1)) && from.y == 6)
			addIfPossible(from + Point(0, -2));
	}

	return pawnPoints;
}

Chess::Piece::~Piece()
{
	delete pieceMovement;
}
