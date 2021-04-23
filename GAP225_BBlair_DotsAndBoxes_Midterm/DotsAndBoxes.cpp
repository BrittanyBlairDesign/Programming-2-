/*
	DotAndBoxes.cpp
	Brittany Blair
*/

#include <iostream>
#include "Board.h"
#include "Player.h"

int main()
{
	// Print Game Title
	std::cout << " Dots and Boxes " << std::endl;
	std::cout << std::endl;

	// Get Game board Size ( 5 x 5 board)
	int W = 5, H = 5;
	//std::cout << "How Wide should the game board be?	( 2 at minimum )" << std::endl;
	//
	//std::cin >> W;
	//
	//std::cout << "How High should the Game Board Be?	( 2 at minimum )" << std::endl;
	//
	//std::cin >> H;

	Board GameBoard(W, H);

	std::cout << "How many Players? (2 at minimum)" << std::endl;

	int numPlayers;
	std::cin >> numPlayers;
	
	// Create an Vector with all players.
	std::vector<Player> Players;
	for (int i = 0; i < numPlayers; ++i)
	{
		Players.push_back(Player(i+1, &GameBoard));
	}

	while(true)
	{
		system("CLS");
		GameBoard.DrawBoard();
		std::cout << std::endl;
		
		for (int i = 0; i < numPlayers;)
		{
			// Print the players name
			Players[i].PrintName();

			// Find out the the player's next Direction
			std::cout << std::endl << "Would you like to make a (h)orizontal or (v)ertical move? ( (q)uit )";
			std::cout << std::endl;
			char move;
			std::cin >> move;

			if (move == 'h' || move == 'H')
			{
				// How Many moves to the left?
				std::cout << "How many places to the left would you like to move? ( 1 - " << GameBoard.GetShort() << ')' << std::endl;

				int x, y;
				std::cin >> x;

				std::cout << "How many rows down would you like to move? ( 1 - " << GameBoard.GetLong() << ')' << std::endl;

				std::cin >> y;

				if (x > GameBoard.GetShort() || y > GameBoard.GetLong() || x <= 0 || y <= 0)
				{
					std::cout << " Im sorry but the coordinate : " << x << ',' << y << " doesn't exist.";
				}
				else
				{
					if (Players[i].HorizontalMove(x, y))
					{
						system("CLS");
						GameBoard.DrawBoard();
						++i;
					}
				}
			}
			else if (move == 'v' || move =='V')
			{
				// How Many moves to the left?
				std::cout << "How many places to the left would you like to move? ( 1 - " << GameBoard.GetLong() << ')' << std::endl;

				int x, y;
				std::cin >> x;

				std::cout << "How many rows down would you like to move? ( 1 - " << GameBoard.GetShort() << ')' << std::endl;

				std::cin >> y;

				if (x > GameBoard.GetLong() || y > GameBoard.GetShort() || x <= 0 || y <= 0)
				{
					std::cout << " Im sorry but the coordinate : " << x << ',' << y << " doesn't exist.";
				}
				else
				{
					if (Players[i].VerticalMove(x, y))
					{
						system("CLS");
						GameBoard.DrawBoard();
						++i;
					}
				}
			}
			else if (move == 'q' || move == 'Q')
			{
				return 0;
			}
			else
			{
				std::cout << "I'm sorry, I don't Understand the request." << std::endl;
			}
		}
	}
}