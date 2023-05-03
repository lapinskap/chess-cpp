#include "ChessBishop.h"
#include "ChessBoard.h"


Chess::Points Chess::Bishop::GetAvailableMovement(const Board& board) const
{
	Points avaliableMoves;

	const Point currentPos = GetPosition();
	for (int i = currentPos.x - 1; i >= 1; i--)
		if (!AddPoint(Point(i, currentPos.y - (currentPos.x - i)), GetColor(), board, avaliableMoves))
			break;
	for (int i = currentPos.x + 1; i <= Board::BOARD_CELL_X; i++)
		if (!AddPoint(Point(i, currentPos.y - (i - currentPos.x)), GetColor(), board, avaliableMoves))
			break;
	for (int i = currentPos.x - 1; i >= 1; i--)
		if (!AddPoint(Point(i, currentPos.y + (currentPos.x - i)), GetColor(), board, avaliableMoves))
			break;
	for (int i = currentPos.x + 1; i <= Board::BOARD_CELL_X; i++)
		if (!AddPoint(Point(i, currentPos.y + (i - currentPos.x)), GetColor(), board, avaliableMoves))
			break;

	return avaliableMoves;
}
char Chess::Bishop::GetPieceDisplay()
{
	return 'B';
}
