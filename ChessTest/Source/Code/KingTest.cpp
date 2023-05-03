#include "UnitTest++/UnitTestPP.h";
#include "UnitTest++/CurrentTest.h";
#include "Engine/ChessBoard.h";
#include "Engine/ChessKing.h";
#include "Engine/ChessPawn.h";
#include "Engine/ChessDefinitions.h";

namespace
{
	TEST(KingAttackSelfPiece)
	{
		Chess::Board board;

		Chess::Point from({ 1,2 });
		Chess::King* king = new Chess::King(from, Chess::Color::Black);
		board.AddPiece(king);

		Chess::Point to({ 1,1 });
		{
			Chess::King* king = new Chess::King(to, Chess::Color::Black);
			board.AddPiece(king);
		}

		board.Move(king->GetPosition(), to);

		Chess::Piece* piece = board.GetPieceAt(from);
		CHECK(piece);
		if (piece)
			CHECK_EQUAL(king, piece);
	}

	TEST(KingAttack)
	{
		Chess::Board board;

		{
			Chess::King* king = new Chess::King({ 3,1 }, Chess::Color::Black);
			board.AddPiece(king);

			Chess::Point to({ 3,2 });
			{
				Chess::King* king = new Chess::King(to, Chess::Color::White);
				board.AddPiece(king);
			}

			{
				board.Move(king->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(to);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(king->GetPosition(), piece->GetPosition());
			}
		}

		{
			Chess::King* king = new Chess::King({ 3,4 }, Chess::Color::Black);
			board.AddPiece(king);

			Chess::Point to({ 4,5 });
			{
				Chess::King* king = new Chess::King(to, Chess::Color::White);
				board.AddPiece(king);
			}

			{
				board.Move(king->GetPosition(), to);

				Chess::Piece* piece = board.GetPieceAt(to);
				CHECK(piece);
				if (piece)
					CHECK_EQUAL(king->GetPosition(), piece->GetPosition());
			}
		}
	}

	TEST(KingMovement)
	{
		Chess::Board board;

		Chess::King* king = new Chess::King({ 4,1 }, Chess::Color::White);
		board.AddPiece(king);

		{
			Chess::Point to({ 4,2 });

			board.Move(king->GetPosition(), to);

			CHECK(board.GetPieceAt(to));
		}

		{
			Chess::Point from({ 2,1 });
			king->SetPosition(from);
			Chess::Point to({ 4,1 });

			board.Move(king->GetPosition(), to);

			CHECK(board.GetPieceAt(from));
		}

		{
			Chess::Point from({ 1,1 });
			king->SetPosition(from);
			Chess::Point to({ 25,20 });

			board.Move(king->GetPosition(), to);

			CHECK(board.GetPieceAt(from));
		}

		{
			Chess::Point from({ 4,5 });
			king->SetPosition(from);
			Chess::Point to({ 6,7 });

			board.Move(king->GetPosition(), to);

			CHECK(board.GetPieceAt(from));
		}


		{
			Chess::Point from({ 4,4 });
			king->SetPosition(from);
			Chess::Point to({ 1,4 });

			board.Move(king->GetPosition(), to);

			CHECK(board.GetPieceAt(from));
		}
	}
}