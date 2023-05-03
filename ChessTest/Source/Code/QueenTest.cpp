#include "UnitTest++/UnitTestPP.h";
#include "UnitTest++/CurrentTest.h";
#include "Engine/ChessBoard.h";
#include "Engine/ChessQueen.h";
#include "Engine/ChessDefinitions.h";

namespace
{
	TEST(QueenAttackSelfPiece)
	{
		Chess::Board board;

		{
			Chess::Queen* queen = new Chess::Queen({ 1,7 }, Chess::Color::Black);
			board.AddPiece(queen);

			
			Chess::Point to({ 1,1 });
			{
				Chess::Queen* queen = new Chess::Queen(to, Chess::Color::Black);
				board.AddPiece(queen);
			}

			{
				Chess::Point from(queen->GetPosition());
				board.Move(queen->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(from);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(queen, piece);
			}
		}
	}

	TEST(QueenAttack)
	{
		Chess::Board board;

		{
			Chess::Queen* queen = new Chess::Queen({ 3,1 }, Chess::Color::Black);
			board.AddPiece(queen);

			{
				Chess::Queen* queen = new Chess::Queen({ 3,7 }, Chess::Color::White);
				board.AddPiece(queen);
			}

			Chess::Point to({ 3,8 });
			{
				Chess::Queen* queen = new Chess::Queen(to, Chess::Color::White);
				board.AddPiece(queen);
			}

			{
				Chess::Point from(queen->GetPosition());
				board.Move(queen->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(from);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(queen, piece);
			}
		}

		{
			Chess::Queen* queen = new Chess::Queen({ 3,4 }, Chess::Color::Black);
			board.AddPiece(queen);

			Chess::Point to({ 6,7 });
			{
				Chess::Queen* queen = new Chess::Queen(to, Chess::Color::White);
				board.AddPiece(queen);
			}

			{
				board.Move(queen->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(to);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(queen, piece);
			}
		}
	}

	TEST(QueenMovement)
	{
		Chess::Board board;

		Chess::Queen* queen = new Chess::Queen({ 8,1 }, Chess::Color::White);
		board.AddPiece(queen);

		{
			Chess::Point to({ 8,8 });

			board.Move(queen->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		queen->SetPosition({ 7,1 });
		{
			Chess::Point to({ 7,8 });

			board.Move(queen->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		{
			Chess::Point from(queen->GetPosition());
			Chess::Point to({ 20,25 });

			board.Move(from, to);

			CHECK(board.GetPieceAt(from));
		}

		queen->SetPosition({ 4,5 });
		{
			Chess::Point to({ 6,7 });

			board.Move(queen->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		queen->SetPosition({ 4,4 });
		{
			Chess::Point to({ 1,4 });

			board.Move(queen->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}
	}
}