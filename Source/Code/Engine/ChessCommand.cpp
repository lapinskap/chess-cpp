#include "ChessCommand.h"
#include "ChessBoard.h"
#include "ChessPiece.h"

Chess::Command::~Command()
{
	delete capturedPiece;
}

Chess::Command::Command(Command&& other)
{
	capturedPiece = other.capturedPiece;
	other.capturedPiece = nullptr;
	from = other.from;
	to = other.to;
}

void Chess::Command::operator == (Command&& other)
{
	capturedPiece = other.capturedPiece;
	other.capturedPiece = nullptr;
	from = other.from;
	to = other.to;
}

bool Chess::Command::IsValid(const Board& board) const
{
	if (!board.IsValid(to))
		return false;

	Piece* piece = board.GetPieceAt(from);
	if (!piece)
		return false;

	if (!board.IsValidMovement(piece, to))
		return false;

	return true;
}

void Chess::Command::Do(Board& board)
{
	Piece* piece = board.GetPieceAt(from);
	if (Piece* other_piece = board.GetPieceAt(to))
	{
		if (piece->GetColor() == other_piece->GetColor())
			return;

		capturedPieceType = other_piece->GetType();
		board.RemovePiece(other_piece);
	}

	piece->SetPosition(to);
	piece->OnMoved();
}

void Chess::Command::Undo(Board& board)
{
	Piece* piece = board.GetPieceAt(to);
	piece->SetPosition(from);

	if (capturedPieceType)
	{
		Piece* other_piece = Piece::CreatePiece(capturedPieceType);
		other_piece->SetPosition(to);
		other_piece->SetColor(piece->GetColor());
		board.AddPiece(other_piece);
	}

	capturedPiece = nullptr;
}