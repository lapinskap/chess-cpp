#include "ChessPawn.h"
#include "ChessBoard.h"



Chess::Points Chess::Pawn::GetAvailableMovement(const Board& board) const
{
	Points avaliableMoves;
	const Point currentPos = GetPosition();
	const int pointY = GetColor() == Color::White ? 1 : -1;
	if (const Piece* piece = board.GetPieceAt(Point(currentPos.x - 1, currentPos.y + pointY)))
		AddPoint(piece->GetPosition(), GetColor(), board, avaliableMoves);

	if (const Piece* piece = board.GetPieceAt(Point(currentPos.x + 1, currentPos.y + pointY)))
		AddPoint(piece->GetPosition(), GetColor(), board, avaliableMoves);


	const Point oneStep(Point(currentPos.x, currentPos.y + pointY));
	if (const Piece* piece = board.GetPieceAt(oneStep))
		return avaliableMoves;

	AddPoint(oneStep, GetColor(), board, avaliableMoves);

	if (!isFirstMove) return avaliableMoves;



	const Point twoStep(Point(currentPos.x, currentPos.y + (pointY * 2)));
	if (const Piece* piece = board.GetPieceAt(twoStep))
		return avaliableMoves;

	AddPoint(twoStep, GetColor(), board, avaliableMoves);

	return avaliableMoves;
}
void Chess::Pawn::OnMoved()
{
	isFirstMove = false;
}
char Chess::Pawn::GetPieceDisplay()
{
	return 'P';
}
