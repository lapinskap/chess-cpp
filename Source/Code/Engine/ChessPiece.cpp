#include "ChessPiece.h"
#include "ChessKnight.h"
#include "ChessBoard.h"


Chess::Piece::~Piece() 
{

}
Chess::Piece::Piece(Chess::Point pos_, Chess::Color color_)
{
	SetPosition(pos_);
	SetColor(color_);
}
Chess::Point Chess::Piece::GetPosition() const
{
	return position;
}

void Chess::Piece::SetPosition(Chess::Point pos)
{
	position = pos;
}
Chess::Color Chess::Piece::GetColor() const 
{
	return color;
}
void Chess::Piece::SetColor(Color color_) 
{
	color = color_;
}
bool Chess::Piece::AddPoint(Chess::Point point, Chess::Color color_, const Chess::Board& board, Chess::Points& points) const
{
	if (!board.IsValid(point))
		return false;

	if (Chess::Piece* piece = board.GetPieceAt(point))
	{
		if (piece->GetColor() == color_)
			return false;

		points.push_back(point);
		return false;
	}

	points.push_back(point);
	return true;
}