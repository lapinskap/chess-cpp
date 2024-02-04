#include "ChessBoard.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

const Chess::Point Chess::Board::Size(8, 8);

Chess::Board::~Board()
{
	for (Piece* piece : pieces)
		delete piece;
}


void Chess::Board::Setup()
{
	for (int i = (int)PieceType::Rook; i <= (int)PieceType::Bishop; i++)
	{
		Piece* pieceWhiteLeft = new Piece((PieceType)i, Color::White, Point(i, 0));
		pieces.push_back(pieceWhiteLeft);

		Piece* pieceWhiteRight = new Piece((PieceType)i, Color::White, Point(7 - i, 0));
		pieces.push_back(pieceWhiteRight);

		Piece* pieceBlackLeft = new Piece((PieceType)i, Color::Black, Point(i, 7));
		pieces.push_back(pieceBlackLeft);

		Piece* pieceBlackRight = new Piece((PieceType)i, Color::Black, Point(7 - i, 7));
		pieces.push_back(pieceBlackRight);
	}

	Piece* queenWhite = new Piece(PieceType::Queen, Color::White, Point(3, 0));
	pieces.push_back(queenWhite);
	Piece* kingWhite = new Piece(PieceType::King, Color::White, Point(4, 0));
	pieces.push_back(kingWhite);

	
	Piece* queenBlack = new Piece(PieceType::Queen, Color::Black, Point(3, 7));
	pieces.push_back(queenBlack);
	Piece* kingBlack = new Piece(PieceType::King, Color::Black, Point(4, 7));
	pieces.push_back(kingBlack);
	
	for (int i = 0; i < 8; i++)
	{
		Piece* pawn = new Piece(PieceType::Pawn, Color::White, Point(i, 1));
		pieces.push_back(pawn);
	}

	for (int i = 0; i < 8; i++)
	{
		Piece* pawn = new Piece(PieceType::Pawn, Color::Black, Point(i, 6));
		pieces.push_back(pawn);
	}

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
	for (int i = 7; i >= 0; i--)
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
					std::cout << "error";
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

Chess::Piece* Chess::Board::GetPieceAt(Point p) const {
	for (Piece* piece : pieces) {
		if (piece->GetPosition() == p) 
			return piece;
	}

	return nullptr;
}


bool Chess::Board::IsValid(Point p) const
{
	return p.x >= 0 && p.x <= 7 && p.y >= 0 && p.y <= 7;
}

void Chess::Board::Move(Point from, Point to)
{
	if (!IsValid(to))
		return;

	if (Piece* piece = GetPieceAt(from)) {

		const Points availableMovementList = piece->GetAvailableMovement(*this);

		//if (std::ranges::contains(availableMovementList, to))
		if (std::find(availableMovementList.begin(), availableMovementList.end(), to) != availableMovementList.end())
			piece->SetPosition(to);
	}
}