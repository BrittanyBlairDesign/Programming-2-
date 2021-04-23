#pragma once

/*
	Tile.h
	Brittany Blair
*/


// Contains my Board Class Information.
class Tile
{
public:
	// Tile Constructor Takes in a Board Pointer, and a Character value.
	Tile(char tileChar)
		:m_char(tileChar)
	{};

	// Prints the current Tile's Character.
	void PrintTile();

	// Returns the Tile's Current Character.
	char const GetTileChar();

	// Changes the Current Tile's character.
	void ChangeTile(char newChar);

private:

	char m_char;
};