#include "ChessPiece.h"

Chess::Piece::Piece(PieceType type_, Color color_, Point position_)
	:type(type_),
	color(color_),
	position(position_)
{
	switch (type)
	{
		case Chess::PieceType::Knight:
			pieceMovement = new KnightMovement;
			break;
	}
}

Chess::Point Chess::Piece::GetPosition() const
{
	return position;
}

void Chess::Piece::SetPosition(Chess::Point pos)
{
	position = pos;
}

Chess::PieceType Chess::Piece::GetType() const
{
	return type;
}

Chess::Color Chess::Piece::GetColor() const
{
	return color;
}

void Chess::Piece::SetColor(Color color_)
{
	color = color_;
}


Chess::Points Chess::Piece::GetAvailableMovement(const Board& board) const
{
	return pieceMovement->GetAvailableMovement(GetPosition(), GetColor(), board);
}