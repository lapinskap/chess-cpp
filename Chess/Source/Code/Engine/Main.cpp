#include <iostream>
#include <string>

#include "ChessBoard/ChessBoard.h"

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

		if (input == "f") {
			std::cout << "you paid respect succesfully\n\n\n\n\n\n\n" << std::endl;
			std::cout << "nnn.................................." << std::endl;
			std::cout << "nnn.................................." << std::endl;
			std::cout << "nice;)" << std::endl;
			std::cout << "\n\n\n\n\n\n\n nigger" << std::endl;

		}
		if (input.length() < 2)
			continue;

		//board.GetPieceAt(Chess::Point(input[0], input[1]))

		Chess::Point startPos(input[0], input[1]);
		Chess::Piece* piece = board.GetPieceAt(startPos);

		std::cout << "test1" << input[2] << input << std::endl;

		
		// TODO: Parse the input
		// e2 e4
		if (input[2] == ' ' && input.size() == 5)
			board.Move(startPos, Chess::Point(input[3], input[4]));


		// a1?
		// TODO: Display all the moves
	
		if (input[2] == '?') {
			if (!piece)
				continue;

			std::cout << "test2" << std::endl;

			Chess::Points movement = piece->GetAvailableMovement(board);
			for (Chess::Point p : movement)
				std::cout << p << "\n";
			continue;
		}

		// if (Piece* piece = board.GetPieceAt(pos))
		// {
		//	  Points movement = piece->GetAvailableMovement();
		//	  for (Point p : movement)
		//		std::cout << p << " ";
		// 
		//	  std::cout << std::endl;
		// }
		//
	}

	return 0;
}