#include "UnitTest++/UnitTestPP.h";
#include "UnitTest++/CurrentTest.h";
#include "Engine/ChessBoard.h";
#include "Engine/ChessPawn.h";
#include "Engine/ChessDefinitions.h";

namespace 
{
	TEST(PawnAttackSelfPiece)
	{
		Chess::Board board;

		{
			Chess::Point from({ 2,4 });
			Chess::Pawn* pawn = new Chess::Pawn(from, Chess::Color::White);
			board.AddPiece(pawn);

			Chess::Point to({ 3,5 });
			{
				Chess::Pawn* pawn = new Chess::Pawn(to, Chess::Color::White);
				board.AddPiece(pawn);
			}

			{
				board.Move(pawn->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(from);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(pawn, piece);
			}
		}
	}

	TEST(PawnAttack) 
	{
		Chess::Board board;

		{
			Chess::Pawn* pawn = new Chess::Pawn({2,4}, Chess::Color::White);
			board.AddPiece(pawn);

			Chess::Point to({ 3,5 });
			{
				Chess::Pawn* pawn = new Chess::Pawn(to, Chess::Color::Black);
				board.AddPiece(pawn);
			}

			{
				board.Move(pawn->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(to);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(pawn, piece);
			}
		}
	}

	TEST(PawnZergRush) 
	{
		Chess::Board board;

		{
			Chess::Pawn* pawn = new Chess::Pawn({ 2,2 }, Chess::Color::White);
			board.AddPiece(pawn);

			Chess::Point from(pawn->GetPosition());
			{
				Chess::Point to({ 2,7 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(from));
			}

			{
				Chess::Point to({ 2,8 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(from));
			}
		}

		{
			Chess::Pawn* pawn = new Chess::Pawn({ 2,7 }, Chess::Color::Black);
			board.AddPiece(pawn);

			Chess::Point from(pawn->GetPosition());
			{
				Chess::Point to({ 2,2 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(from));
			}

			{
				Chess::Point to({ 2,1 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(from));
			}
		}
	}


	TEST(PawnMovement) 
	{
		Chess::Board board;

		{
			Chess::Pawn* pawn = new Chess::Pawn({ 2,2 }, Chess::Color::White);
			board.AddPiece(pawn);
			
			{
				Chess::Point to({ 2,4 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(to));
			}

			{
				Chess::Point from(pawn->GetPosition());
				Chess::Point to({ 2,6 });

				board.Move(from, to);

				CHECK(board.GetPieceAt(from));
			}

			{
				Chess::Point to({ 2,5 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(to));
			}
		}

		{

			Chess::Pawn* pawn = new Chess::Pawn({ 3,2 }, Chess::Color::White);
			board.AddPiece(pawn);
			{
				Chess::Point to({ 3,3 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(to));
			}

			{
				Chess::Point from(pawn->GetPosition());
				Chess::Point to({ 3,5 });

				board.Move(from, to);

				CHECK(board.GetPieceAt(from));
			}

			{
				Chess::Point to({ 3,4 });

				board.Move(pawn->GetPosition(), to);

				CHECK(board.GetPieceAt(to));
			}
		}
	}

	
}