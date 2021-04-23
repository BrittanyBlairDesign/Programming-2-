#pragma once

/*
	Board.h
	Brittany Blair
*/

#include <iostream>
#include <vector>
#include "Tile.h"

class Board
{
public:
	// Board Constructor takes in two Int Values a Width and a Height. It then uses them to create the Tile vector's size.
	Board(int W, int H)
		:m_shortSize(W-1)		// If its a 5 x 5 the tiles are 9 x 9.  5x2 = 10 -1 = 9. 5 dots, 4 blanks.
		, m_longSize(H)
	{

			// Adding Tiles to the Vector of Tiles. this should give me 40 playable ' ' tiles. across 2 vectors
			for (int i = 0; i < m_shortSize; i++)			
			{
				for (int j = 0; j < m_longSize; j++)		
				{
					m_ShortRows.push_back(Tile(' '));
				}
			}

			for (int i = 0; i < m_longSize; ++i)
			{
				for (int j = 0; j < m_shortSize; ++j)
				{
					m_LongRows.push_back(Tile(' '));
				}
			}

	};

	// Prints the game board.
	void DrawBoard();

	// Gets a Horizontal Tile's character at a spesific location. Returns a refrence of it.
	char const GetHorizontalTile(int W, int H);

	// Gets a Vertical Tile's character at a spesific location. Returns a refrence of it.
	char const GetVerticalTile(int W, int H);

	// Changes a Horizontal Tile at a spesific Location in the Vector.
	void ChangeHorizontalTile(int W, int H, char newChar);

	// Changes a Horizontal Tile at a spesific Location in the Vector.
	void ChangeVerticalTile(int W, int H, char newChar);

	// Get the ShortLength of the board
	const int GetShort() { return m_shortSize; }

	// Get the LongLenght of the board
	const int GetLong() { return m_longSize; }

	~Board() 
	{
		m_ShortRows.clear();
		m_LongRows.clear();
	}

private:
	const int m_shortSize, m_longSize;
	std::vector<Tile> m_ShortRows;
	std::vector<Tile> m_LongRows;
};