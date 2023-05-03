#pragma once

#include "ChessDefinitions.h"
#include "ChessCommand.h"

namespace Chess
{
	class Game;

	class Player
	{
	public:

		virtual ~Player() = default;

		virtual Command MakeMove(Game&) const = 0;

		virtual Color GetColor() const = 0;
		virtual void SetColor(Color) = 0;

	protected:
	};
}