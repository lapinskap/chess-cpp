#include "ChessBoard.h"

#include <iostream>
#include <vector>

Chess::Board::~Board()
{
	for (Piece* piece : pieces)
		delete piece;
}

void Chess::Board::Setup()
{
	Piece* piece = new Piece(PieceType::Knight, Color::White, Point(4, 4));
	pieces.push_back(piece);
}

void Chess::Board::AddPiece(Piece* piece)
{
	pieces.push_back(piece);
}

void Chess::Board::RemovePiece(Piece* piece)
{
	std::erase(pieces, piece);
	delete piece;
}


void Chess::Board::Print() const
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "[";
			if (Piece* piece = GetPieceAt(Point(j, i)))
			{
				switch (piece->GetType())
				{
				case PieceType::Bishop: std::cout << "B"; break;
				case PieceType::Knight: std::cout << "N"; break;
				case PieceType::Rook: std::cout << "R"; break;
				case PieceType::Queen: std::cout << "Q"; break;
				case PieceType::King: std::cout << "K"; break;
				case PieceType::Pawn: std::cout << "P"; break;
				default:
					// Error
					break;
				}
			}
			else
				std::cout << " ";
			std::cout << "]";
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
	// TODO: check the borders *ukraine*
	return false;
}

void Chess::Board::Move(Point from, Point to)
{
	if (!IsValid(to))
		return;

	// TODO: get piece movement and check if to is located in it
	if (Piece* piece = GetPieceAt(from))
		piece->SetPosition(to);
}