#include "ChessKing.h"
#include "ChessQueen.h"
#include "ChessBoard.h"



Chess::Points Chess::King::GetAvailableMovement(const Board& board) const
{
	Points avaliableMoves;

	const Point currentPos = GetPosition();
	for (int i = currentPos.x - 1; i <= currentPos.x + 1; i++)
		for (int j = currentPos.y - 1; j <= currentPos.y + 1; j++)
			AddPoint(Point(i, j), GetColor(), board, avaliableMoves);

	return avaliableMoves;
}
char Chess::King::GetPieceDisplay()
{
	return 'K';
}