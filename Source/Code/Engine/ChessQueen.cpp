#include "ChessQueen.h"
#include "ChessBishop.h"
#include "ChessRook.h"
#include "ChessBoard.h"



Chess::Points Chess::Queen::GetAvailableMovement(const Board& board) const
{
	Chess::Rook* rookMovement = new Rook(GetPosition(), GetColor());
	Chess::Bishop* bishopMovement = new Bishop(GetPosition(),GetColor());

	Points rookPoints = rookMovement->GetAvailableMovement(board);
	Points bishopPoints = bishopMovement->GetAvailableMovement(board);

	rookPoints.insert(rookPoints.end(), bishopPoints.begin(), bishopPoints.end());

	delete rookMovement;
	delete bishopMovement;

	return rookPoints;
}
char Chess::Queen::GetPieceDisplay()
{
	return 'Q';
}