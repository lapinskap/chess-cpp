#include <iostream>
#include <string>


#include "ChessBoard.h"
#include "ChessPoint.h"
#include "ChessPiece.h"
#include "ChessKnight.h"

int main()
{
	std::cout << "Welcome to Chess" << std::endl;

	Chess::Board board;
	board.Setup();
	while (true)
	{
		board.Print();

		std::string input;
		std::getline(std::cin, input);

		if (input == "q")
			break;

		Chess::Point from(input[0], input[1]);
		Chess::Piece* piece = board.GetPieceAt(from);
		if (!piece) continue;

		char symbol = (char)input[2];

		if (symbol == '?')
			board.DisplayAvaliableMove(piece);
		if (symbol == ' ')
			if (input.size() == 5)
				board.Move(piece->GetPosition(), Chess::Point(input[3],input[4]));
	}

	return 0;
}
