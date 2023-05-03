#include "ChessRook.h"
#include "ChessBoard.h"



Chess::Points Chess::Rook::GetAvailableMovement(const Board& board) const
{
	Points avaliableMoves;

	const Point currentPos = GetPosition();
	for (int i = currentPos.x; i >= 1; i--)
		if (!AddPoint(Point(i - 1, currentPos.y), GetColor(), board, avaliableMoves))
			break;
	for (int i = currentPos.x; i <= Board::BOARD_CELL_X; i++)
		if(!AddPoint(Point(i + 1, currentPos.y), GetColor(), board, avaliableMoves))
			break;
	for (int i = currentPos.y; i >= 1; i--)
		if(!AddPoint(Point(currentPos.x, i - 1), GetColor(), board, avaliableMoves))
			break;
	for (int i = currentPos.y ; i <= Board::BOARD_CELL_Y; i++)
		if(!AddPoint(Point(currentPos.x, i + 1), GetColor(), board, avaliableMoves))
			break;

	return avaliableMoves;
}
char Chess::Rook::GetPieceDisplay()
{
	return 'R';
}