/*
	Board.cpp
	Brittany Blair
*/
#include <iostream>
#include <string>
#include "Board.h"

void Board::DrawBoard()
{
	// Bool that checks if we are working on printing out a short row, or a long row
	bool isShortRow = true;

	// int valus that are used when checking if the current i or j value is divisible by the short size or long size.
	int checkShort = 1;
	int CheckLong = 1;

	// Gets the Vectors sizes for the for loop.
	int ShortVector = m_ShortRows.size();			// if its a 5x5 should be 20.
	int LongVector = m_LongRows.size();				// if its a 5x5 grid should be 20.

	for (int i = 0; i < ShortVector;)
	{
		for (int j = 0; j < LongVector;)
		{
			if (isShortRow && i < ShortVector)		// Check if we are printing a short row or a long row. ** And now making sure that i is not finished before continuing the loop.
			{
				if (checkShort % m_shortSize == 0)	// if check ( gets set to i after first loop) can be evenly divided by the short row size
				{
					if (checkShort < ShortVector)
					{
						++checkShort;				// increment check short to avoid an infinate loop.
					
						std::cout << '.';			// Add our last dot to the board.
						std::cout << std::endl;	// End the line
						isShortRow = false;	
					}								// We are now finished pinting this short row.										
				}

				else
				{

					std::cout << '.';				// Add a dot first
					m_ShortRows[i].PrintTile();		// Then print the tile.
					++i;							// We only increment i if its time to print a short row.
					checkShort = i;					// Set check short to i so that when we check if i is divisible we are checking the correct number.
					if (i == ShortVector)
					{
						std::cout << '.';
					}
					//std::cout << i;	// To debug the issue of the Vector Causing the program to crash when trying to print a non-existant tile.
				}

			}
			else
			{										// If we are printing a Long row we will be working with J instead of I
				if (CheckLong % m_longSize == 0)
				{
					if (CheckLong <= LongVector)		// Make sure that the checklong value isnt going above the size of the vector.
					{
						CheckLong++;				// Increment long so that when the loop comes  back to print a long row it does not create an infinate bounce back between the two.

						std::cout << std::endl;		// End the line
						isShortRow = true;			// We will be printing a short row next.
					}
					else if (j == 0)				// Fail safe for if my loop refuses to close.
					{								// Fors some reason J keeps setting itself back to 0 so this should stop it from making an endless loop.
						j = LongVector;
						break;
					}

				}
				else
				{
					m_LongRows[j].PrintTile();		// We Print the tile First
					std::cout << ' ';				// Then we print a space char.
					++j;							// We only Increment the j when we are working with long rows.

					//std::cout << j;	// To debug the issue of printing more tiles than it should. **** J is looping back around to 1 again for some reason.
					CheckLong = j;					// Set checklong to j so we are always checking the correct value for the beginning of this if statement.
				}
			}
		}
	}
}

char const Board::GetHorizontalTile(int W, int H)
{
	// Adjusts H to the propper number to get the correct positon on the game board.
	switch (H)
	{
	case 1:
		H = 0;
		break;
	case 2:
		H = m_shortSize;
		break;
	case 3:
		H = m_shortSize * 2;
		break;
	case 4:
		H = m_shortSize * 3;
		break;
	case 5:
		H = m_shortSize * 4;
		break;
	default:
		H = (H - 1) * m_shortSize;
		break;
	}

	int location = W + H;
	location = location - 1;

	// Get that tile's Character.
	return m_ShortRows[location].GetTileChar();
}

char const Board::GetVerticalTile(int W, int H)
{
	// Adjusts H to the propper number to get the correct positon on the game board.
	switch (H)
	{
	case 1:
		H = 0;
		break;
	case 2:
		H = m_longSize;
		break;
	case 3:
		H = m_longSize * 2;
		break;
	case 4:
		H = m_longSize * 3;
		break;
	default:
		H = (H - 1) * m_longSize;
		break;
	}
	int location = W + H;
	location = location - 1;

	// Get that tile's Character.
	return m_LongRows[location].GetTileChar();
}

void Board::ChangeHorizontalTile(int W, int H, char newChar)
{
	// Adjusts H to the propper number to get the correct positon on the game board.
	switch (H)
	{
	case 1:
		H = 0;
		break;
	case 2:
		H = m_shortSize;
		break;
	case 3:
		H = m_shortSize * 2;
		break;
	case 4:
		H = m_shortSize * 3;
		break;
	case 5:
		H = m_shortSize * 4;
		break;
	default:
		H = (H - 1) * m_shortSize;
		break;
	}
	int location = W + H;
	location = location - 1;
	// Change that tile's Character.
	m_ShortRows[location].ChangeTile(newChar);
}

void Board::ChangeVerticalTile(int W, int H, char newChar)
{
	// Adjusts H to the propper number to get the correct positon on the game board.
	switch (H)
	{
	case 1:
		H = 0;
		break;
	case 2:
		H = m_longSize;
		break;
	case 3:
		H = m_longSize * 2;
		break;
	case 4:
		H = m_longSize * 3;
		break;
	default:
		H = (H - 1) * m_longSize;
		break;
	}
	int location = W + H;
	location = location - 1;
	// Change that tile's Character.
	m_LongRows[location].ChangeTile(newChar);
}