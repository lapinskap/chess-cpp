
#include "ChessBoard.h"
#include "ChessKnight.h"
#include "ChessRook.h"
#include "ChessBishop.h"
#include "ChessPawn.h"
#include "ChessQueen.h"
#include "ChessKing.h"

#include <iostream>
#include <list>

Chess::Board::~Board()
{
	for (Piece* piece : pieces)
		delete piece;
}

void Chess::Board::Setup()
{
	SetupPieces(Color::Black, 8);
	SetupPieces(Color::White, 1);

}
void Chess::Board::SetupPieces(Chess::Color color,int y)
{
	Chess::Rook* left_rock = new Chess::Rook(Chess::Point(1, y),color);
	Chess::Board::AddPiece(left_rock);

	Chess::Knight* left_knight = new Chess::Knight(Chess::Point(2, y), color);
	Chess::Board::AddPiece(left_knight);

	Chess::Bishop* left_bishop = new Chess::Bishop(Chess::Point(3, y),color);
	Chess::Board::AddPiece(left_bishop);

	Chess::Queen* queen = new Chess::Queen(Chess::Point(4, y),color);
	Chess::Board::AddPiece(queen);

	Chess::King* king = new Chess::King(Chess::Point(5, y),color);
	Chess::Board::AddPiece(king);

	Chess::Bishop* right_bishop = new Chess::Bishop(Chess::Point(6, y),color);
	Chess::Board::AddPiece(right_bishop);

	Chess::Knight* right_knight = new Chess::Knight(Chess::Point(7, y), color);
	Chess::Board::AddPiece(right_knight);

	Chess::Rook* right_rock = new Chess::Rook(Chess::Point(8, y), color);
	Chess::Board::AddPiece(right_rock);

	const int posY = (y == 1) ? y + 1 :  y - 1;
	for (int i = 1; i <= 8; i++)
	{
		Chess::Pawn* pawn = new Chess::Pawn(Chess::Point(i, posY), color);
		Chess::Board::AddPiece(pawn);
	}
}
void Chess::Board::Print() const
{
	for (int i = Chess::Board::BOARD_CELL_Y; i > 0; i--)
	{
		for (int j = 1; j <= Chess::Board::BOARD_CELL_X ; j++)
		{
			Point point(j, i);
			std::cout << point << "[";
			if (Piece* piece = GetPieceAt(point))
				std::cout<<piece->GetPieceDisplay();
			else
				std::cout << " ";
			std::cout << "]" << " ";
		}

		std::cout << std::endl;
	}
}

Chess::Piece* Chess::Board::GetPieceAt(Point p) const
{
	for (Piece* piece : pieces)
		if (piece->GetPosition() == p)
			return piece;

	return nullptr;
}

bool Chess::Board::IsValid(Point p) const
{
	if (p.x > 0 && p.x <= BOARD_CELL_X && p.y > 0 && p.y <= BOARD_CELL_Y)
		return true;
	
	return false;
}
bool Chess::Board::IsValidMovement(Piece* piece, Point to) const
{
	for (Point point : piece->GetAvailableMovement(*this))
		if (point == to)
			return true;

	return false;
}
void Chess::Board::Move(Point from, Point to)
{
	if (!IsValid(to)) return;

	Piece* piece = GetPieceAt(from);
	if (!piece) return;
	if (!IsValidMovement(piece, to)) return;

	if (Piece* other_piece = GetPieceAt(to)) 
	{
		if (piece->GetColor() == other_piece->GetColor()) return;
		RemovePiece(other_piece);
	}

	piece->SetPosition(to);
	piece->OnMoved();
}
void Chess::Board::DisplayAvaliableMove(Chess::Piece* piece) 
{
	Chess::Points movement = piece->GetAvailableMovement(*this);
	std::cout << "\n" << "Possible Moves: " << "\n";
	std::cout << "From: " << piece->GetPosition() << " to: ";
	for (Chess::Point p : movement)
		std::cout << p << " ";

	std::cout << "\n";
}
void Chess::Board::RemovePiece(Piece* piece) 
{
	std::erase(pieces, piece);
	//delete piece;
}
void Chess::Board::AddPiece(Piece* piece) 
{
	pieces.push_back(piece);
}