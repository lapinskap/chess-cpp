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

// per color
void Chess::Board::CreateSetOfPieces(Chess::Color color) {
	// defineRookPosition(color,...?) 
	Piece* rookLeft = new Piece(PieceType::Rook, color, Point(0, 0));
	pieces.push_back(rookLeft);
	Piece* knightLeft = new Piece(PieceType::Knight, color, Point(1, 0));
	pieces.push_back(knightLeft);
	Piece* bishopLeft = new Piece(PieceType::Bishop, color, Point(2, 0));
	pieces.push_back(bishopLeft);
	Piece* queen = new Piece(PieceType::Queen, color, Point(3, 0));
	pieces.push_back(queen);
	Piece* king = new Piece(PieceType::King, color, Point(4, 0));
	pieces.push_back(king);
	Piece* bishopRight = new Piece(PieceType::Bishop, color, Point(5, 0));
	pieces.push_back(bishopRight);
	Piece* knightRight = new Piece(PieceType::Knight, color, Point(6, 0));
	pieces.push_back(knightRight);
	Piece* rookRight = new Piece(PieceType::Rook, color, Point(7, 0));
	pieces.push_back(rookRight);
}


void Chess::Board::Setup()
{
	/*Piece* piece = new Piece(PieceType::Knight, Color::White, Point(4, 4));
	pieces.push_back(piece);*/

	Piece* rookLeftWhite = new Piece(PieceType::Rook, Color::White, Point(0, 0));
	pieces.push_back(rookLeftWhite);
	Piece* knightLeftWhite = new Piece(PieceType::Knight, Color::White, Point(1, 0));
	pieces.push_back(knightLeftWhite);
	Piece* bishopLeftWhite = new Piece(PieceType::Bishop, Color::White, Point(2, 0));
	pieces.push_back(bishopLeftWhite);
	Piece* queenWhite = new Piece(PieceType::Queen, Color::White, Point(3, 0));
	pieces.push_back(queenWhite);
	Piece* kingWhite = new Piece(PieceType::King, Color::White, Point(4, 0));
	pieces.push_back(kingWhite);
	Piece* bishopRightWhite = new Piece(PieceType::Bishop, Color::White, Point(5, 0));
	pieces.push_back(bishopRightWhite);
	Piece* knightRightWhite = new Piece(PieceType::Knight, Color::White, Point(6, 0));
	pieces.push_back(knightRightWhite);
	Piece* rookRightWhite = new Piece(PieceType::Rook, Color::White, Point(7, 0));
	pieces.push_back(rookRightWhite);

	Piece* rookLeftBlack = new Piece(PieceType::Rook, Color::Black, Point(0, 7));
	pieces.push_back(rookLeftBlack);
	Piece* knightLeftBlack = new Piece(PieceType::Knight, Color::Black, Point(1, 7));
	pieces.push_back(knightLeftBlack);
	Piece* bishopLeftBlack = new Piece(PieceType::Bishop, Color::Black, Point(2, 7));
	pieces.push_back(bishopLeftBlack);
	Piece* queenLeftBlack = new Piece(PieceType::Queen, Color::Black, Point(3, 7));
	pieces.push_back(queenLeftBlack);
	Piece* kingLeftBlack = new Piece(PieceType::King, Color::Black, Point(4, 7));
	pieces.push_back(kingLeftBlack);
	Piece* bishopRightBlack = new Piece(PieceType::Bishop, Color::Black, Point(5, 7));
	pieces.push_back(bishopRightBlack);
	Piece* knightRightBlack = new Piece(PieceType::Knight, Color::Black, Point(6, 7));
	pieces.push_back(knightRightBlack);
	Piece* rookRightBlack = new Piece(PieceType::Rook, Color::Black, Point(7, 7));
	pieces.push_back(rookRightBlack);

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