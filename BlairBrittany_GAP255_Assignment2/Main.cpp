/*
	Brittany Blair
	GAP 255 - Assignment 2
	Maze Game
*/

#include <iostream>
#include <vector>
#include "Grid.h"
#include "Tile.h"
#include "Player.h"

int main()
{
	const size_t Width = 10;
	const size_t Height = 10;
	Grid level1(Width, Height);

	Player Player(level1);
	
	std::vector<Tile> tileGrid;

	for (size_t i = 0; i < level1.GetWidth() * level1.GetHeight(); ++i)
	{
		
	}

	while (Player.PlayingCheck()) 
	{
		system("CLS");
		level1.DrawGrid();
		char input;
		std::cin >> input;
		Player.PlayerMove(level1, input);
	}

}