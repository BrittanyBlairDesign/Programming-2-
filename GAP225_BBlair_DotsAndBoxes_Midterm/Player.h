#pragma once

/*
	Player.h
	Brittany Blair
*/

#include <string>
#include "Board.h"

// Contains all Player Class information.
class Player
{
public:
	// Player Constructor takes in an int to represent the number player they are, and creates their name as Player + that number.
	Player(int playerNumber, Board* pboard)
		:m_number(playerNumber)
		,m_pBoard(pboard)
	{};

	// Prints the player's name and their score.
	void PrintName();

	// Player Makes a Horizontal Move.
	bool HorizontalMove(int W, int H);

	// Player makes a Vertical Move.
	bool VerticalMove(int W, int H);

private:
	unsigned const int m_number;
	std::string m_name = "Player ";
	Board* m_pBoard;

	char m_vertical = '|';
	char m_horizontal = '-';
};