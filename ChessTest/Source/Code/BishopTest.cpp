#include "UnitTest++/UnitTestPP.h"
#include "UnitTest++/CurrentTest.h"
#include "Engine/ChessBoard.h"
#include "Engine/ChessBishop.h"
#include "Engine/ChessDefinitions.h"

namespace 
{
	TEST(BishopAttackSelfPiece)
	{
		Chess::Board board;

		{
			Chess::Point from({ 2,4 });

			Chess::Bishop* bishop = new Chess::Bishop(from, Chess::Color::White);
			board.AddPiece(bishop);

			Chess::Point to({ 3,5 });
			{
				Chess::Bishop* bishop = new Chess::Bishop(to, Chess::Color::White);
				board.AddPiece(bishop);
			}

			{
				board.Move(bishop->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(from);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(bishop, piece);
			}
		}
	}

	TEST(BishopAttack)
	{
		Chess::Board board;

		{
			Chess::Point from({ 2,4 });
			Chess::Bishop* bishop = new Chess::Bishop(from, Chess::Color::Black);
			board.AddPiece(bishop);

			{
				Chess::Bishop* bishop = new Chess::Bishop({3,5}, Chess::Color::White);
				board.AddPiece(bishop);
			}

			Chess::Point to({ 4,6 });
			{
				Chess::Bishop* bishop = new Chess::Bishop(to, Chess::Color::White);
				board.AddPiece(bishop);
			}


			{
				board.Move(bishop->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(from);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(bishop, piece);
			}
		}

		{
			Chess::Bishop* bishop = new Chess::Bishop({ 6,2 }, Chess::Color::Black);
			board.AddPiece(bishop);

			Chess::Point to({ 8,4 });
			{
				Chess::Bishop* bishop = new Chess::Bishop(to, Chess::Color::White);
				board.AddPiece(bishop);
			}

			{
				board.Move(bishop->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(to);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(bishop, piece);
			}
		}
	}

	TEST(BishopMovement)
	{
		Chess::Board board;

		Chess::Bishop* bishop = new Chess::Bishop({ 3,3 }, Chess::Color::White);
		board.AddPiece(bishop);

		{
			Chess::Point to({ 8,8 });

			board.Move(bishop->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		bishop->SetPosition({3,2});
		{
			Chess::Point to({ 1,4 });

			board.Move(bishop->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		Chess::Point from({ 3,2 });
		bishop->SetPosition(from);
		{
			Chess::Point to({ 20,25 });

			board.Move(bishop->GetPosition(), to);

			CHECK(board.GetPieceAt(from));
		}
	}
}