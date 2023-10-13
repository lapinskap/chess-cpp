#pragma once

namespace Chess
{
	enum class PieceType
	{
		None,
		Pawn,
		Knight,
		Bishop,
		Rook,
		Queen,
		King
	};

	enum class Color
	{
		White,
		Black
	};

	enum class PlayerType
	{
		Human,
		CPU
	};
}