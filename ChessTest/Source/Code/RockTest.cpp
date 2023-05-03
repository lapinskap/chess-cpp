#include "UnitTest++/UnitTestPP.h"
#include "UnitTest++/CurrentTest.h"
#include "Engine/ChessBoard.h"
#include "Engine/ChessRook.h"
#include "Engine/ChessDefinitions.h"

namespace
{
	TEST(RookAttackSelfPiece)
	{
		Chess::Board board;

		{
			Chess::Rook* rook = new Chess::Rook({ 1,7 }, Chess::Color::Black);
			board.AddPiece(rook);

			Chess::Point to({ 1,1 });
			{
				Chess::Rook* rook = new Chess::Rook(to, Chess::Color::Black);
				board.AddPiece(rook);
			}

			{
				Chess::Point from(rook->GetPosition());
				board.Move(from, to);

				Chess::Piece* piece = board.GetPieceAt(from);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(rook, piece);
			}
		}
	}

	TEST(RookAttack)
	{
		Chess::Board board;

		{
			Chess::Rook* rook = new Chess::Rook({ 3,1 }, Chess::Color::Black);
			board.AddPiece(rook);

			{
				Chess::Rook* rook = new Chess::Rook({ 3,7 }, Chess::Color::White);
				board.AddPiece(rook);
			}

			Chess::Point to({ 3,8 });
			{
				Chess::Rook* rook = new Chess::Rook(to, Chess::Color::White);
				board.AddPiece(rook);
			}

			{
				Chess::Point from(rook->GetPosition());
				board.Move(from, to);

				Chess::Piece* piece = board.GetPieceAt(from);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(rook, piece);
			}
		}

		{
			Chess::Rook* rook = new Chess::Rook({ 6,1 }, Chess::Color::Black);
			board.AddPiece(rook);

			Chess::Point to({ 6,8 });
			{
				Chess::Rook* rook = new Chess::Rook(to, Chess::Color::White);
				board.AddPiece(rook);
			}

			{
				board.Move(rook->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(to);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(rook, piece);
			}
		}
	}

	TEST(RookMovement)
	{
		Chess::Board board;

		Chess::Rook* rook = new Chess::Rook({ 8,1 }, Chess::Color::White);
		board.AddPiece(rook);

		{
			Chess::Point to({ 8,8 });

			board.Move(rook->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		rook->SetPosition({ 7,1 });
		{
			Chess::Point to({ 7,8 });

			board.Move(rook->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		{
			Chess::Point from(rook->GetPosition());
			Chess::Point to({ 20,25 });

			board.Move(from, to);

			CHECK(board.GetPieceAt(from));
		}
	}
}