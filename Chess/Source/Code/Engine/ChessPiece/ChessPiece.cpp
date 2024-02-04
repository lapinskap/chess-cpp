#include "ChessPiece.h"
#include "../ChessBoard/ChessBoard.h"

const int maxRadius = 8;

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
		case Chess::PieceType::Pawn:
			pieceMovement = new PawnMovement;
			break;
		case Chess::PieceType::Bishop:
			pieceMovement = new BishopMovement;
			break;
		case Chess::PieceType::Rook:
			pieceMovement = new RookMovement;
			break;
		case Chess::PieceType::Queen:
			pieceMovement = new QueenMovement;
			break;
		case Chess::PieceType::King:
			pieceMovement = new KingMovement;
			break;
		default:
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
	return pieceMovement->GetAvailableMovement(GetPosition(), GetColor(), board, Board::Size.x);
}