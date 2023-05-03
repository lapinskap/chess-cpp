#include <iostream>
#include <string>

#include "Engine/ChessBoard.h"
#include "Engine/ChessPoint.h"
#include "Engine/ChessPiece.h"
#include "Engine/ChessGame.h"

#include "AI/AIPlayer.h"

class ConsolePlayer : public Chess::Player
{
public:

	virtual Chess::Command MakeMove(Chess::Game& game) const override
	{
		while (true)
		{
			std::string input;
			std::getline(std::cin, input);

			if (input == "r")
			{
				game.Rollback();

				game.board.Print();

				continue;
			}

			Chess::Point from(input[0], input[1]);
			Chess::Piece* piece = game.board.GetPieceAt(from);
			if (!piece) 
				continue;

			char symbol = (char)input[2];

			if (symbol == '?')
			{
				game.board.DisplayAvaliableMove(piece);
				continue;
			}

			if (symbol == ' ')
				if (input.size() == 5)
				{
					Chess::Point to(input[3], input[4]);
					return Chess::Command{ from, to };
				}
		}
		
	}

	virtual Chess::Color GetColor() const override
	{
		return Chess::Color::White;
	}

    virtual void SetColor(Chess::Color) override
	{

	}
};

int main(int argc, char** argv)
{
	std::cout << "Welcome to Chess" << std::endl;

	Chess::Game game;
	game.SetupBoard();

	game.players[(int)Chess::Color::White] = new ConsolePlayer;
	game.players[(int)Chess::Color::Black] = new ConsolePlayer;

	while (true)
	{
		game.board.Print();
		game.NextMove();
	}

	return 0;
}
