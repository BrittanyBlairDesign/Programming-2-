/*
	Tile.cpp
	Brittany Blair
*/
#include <iostream>
#include "Tile.h"

void Tile::PrintTile()
{
	// Print out the tile's char.
	std::cout << m_char;
}


char const Tile::GetTileChar()
{
	// Return the Tile's char.
	return m_char;
}


void Tile::ChangeTile(char newChar)
{
	// Assign the tiles new char.
	m_char = newChar;
}