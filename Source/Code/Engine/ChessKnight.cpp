#include "ChessKnight.h"
#include "ChessBoard.h"

 

Chess::Points Chess::Knight::GetAvailableMovement(const Board & board) const
{
	Points avaliableMoves;

	for (int i = -2; i <= 2; i += 4)
		for (int j = -1; j <= 1; j += 2)
		{
			AddPoint(GetPosition() + Point(i, j), GetColor(), board, avaliableMoves);
			AddPoint(GetPosition() + Point(j, i), GetColor(), board, avaliableMoves);
		}

	return avaliableMoves;
}
char Chess::Knight::GetPieceDisplay()
{
	return 'N';
}
