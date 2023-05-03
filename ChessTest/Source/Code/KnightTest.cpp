#include "UnitTest++/UnitTestPP.h"
#include "UnitTest++/CurrentTest.h"
#include "Engine/ChessBoard.h"
#include "Engine/ChessKnight.h"
#include "Engine/ChessDefinitions.h"

namespace 
{
	TEST(KnightAttackSelfPiece)
	{
		Chess::Board board;

		Chess::Point from({ 2,8 });
		Chess::Knight* knight = new Chess::Knight(from, Chess::Color::Black);
		board.AddPiece(knight);

		Chess::Point to({ 1,6 });
		{
			Chess::Knight* knight = new Chess::Knight(to, Chess::Color::Black);
			board.AddPiece(knight);
		}

		board.Move(knight->GetPosition(), to);

		Chess::Piece* piece = board.GetPieceAt(from);
		CHECK(piece);
		if (piece)
			CHECK_EQUAL(knight, piece);

	}

	TEST(KnightMovement) 
	{
		Chess::Board board;

		Chess::Knight* knight = new Chess::Knight({ 2,1 }, Chess::Color::Black);
		board.AddPiece(knight);

		{
			Chess::Point to({ 1,3 });

			board.Move(knight->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		{
			Chess::Point from({ 2,1 });
			knight->SetPosition(from);
			Chess::Point to({ 2,5 });

			board.Move(knight->GetPosition(), to);

			CHECK(board.GetPieceAt(from));
		}

		{
			Chess::Point from({ 2,1 });
			knight->SetPosition(from);
			Chess::Point to({ 3,9 });

			board.Move(knight->GetPosition(), to);

			CHECK(board.GetPieceAt(from));
		}
	}


	TEST(KnightAttack) 
	{
		Chess::Board board;

		Chess::Knight* knight = new Chess::Knight({1,3}, Chess::Color::Black);
		board.AddPiece(knight);

		{
			Chess::Point to({ 2,1 });
			{
				Chess::Knight* piece = new Chess::Knight(to, Chess::Color::White);
				board.AddPiece(piece);
			}

			board.Move(knight->GetPosition(), to);
			
			Chess::Piece* piece = board.GetPieceAt(to);
			CHECK(piece);
			if (piece)
				CHECK_EQUAL(knight, piece);
			
		}

		{
			Chess::Point from(knight->GetPosition());
			Chess::Point to({ 7,9 });
			{
				Chess::Knight* piece = new Chess::Knight(to, Chess::Color::White);
				board.AddPiece(piece);
			}

			board.Move(knight->GetPosition(), to);

			Chess::Piece* piece = board.GetPieceAt(from);
			CHECK(piece);
			if (piece)
				CHECK_EQUAL(knight, piece);
		}

		{
			Chess::Point from(knight->GetPosition());
			Chess::Point to({ 11,25 });
			{
				Chess::Knight* piece = new Chess::Knight(to, Chess::Color::White);
				board.AddPiece(piece);
			}

			board.Move(knight->GetPosition(), to);

			Chess::Piece* piece = board.GetPieceAt(from);
			CHECK(piece);
			if (piece)
				CHECK_EQUAL(knight, piece);

		}

	}

}
