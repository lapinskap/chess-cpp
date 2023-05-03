#pragma once

#include "Engine/ChessPlayer.h"

namespace AI
{
	class Player : public Chess::Player
	{
	public:

		virtual Chess::Command MakeMove(Chess::Game&) const override;

		virtual Chess::Color GetColor() const override { return Chess::Color::Black; }
		virtual void SetColor(Chess::Color) override {}
	};
}
