#pragma once
/*
	Test.h
	Brittany Blair
*/

#include <iostream>
#include "board.h"
#include "Player.h"

void TestChars(const char* pTestName, char value1, char value2)
{
	std::cout << pTestName << ':';
	if (value1 == value2)
	{
		std::cout << "PASSED";
	}
	else
	{
		std::cout << "FAILED";
	}

	std::cout << std::endl;
}

void RunTests()
{
	Board TestBoard(5, 5);
	
	// Test the game board's ability to get a Horizontal tile's char.
	TestChars("Board Horizontal GetTileChar Test 1", TestBoard.GetHorizontalTile(2, 2), ' ');
	TestChars("Board Horizontal GetTileChar Test 2", TestBoard.GetHorizontalTile(1, 1), ' ');
	TestChars("Board Horizontal GetTileChar Test 3", TestBoard.GetHorizontalTile(4, 5), ' ');
	
	// Test the Game board's Ability to get a Vertical Tile's Char.
	TestChars("Board Vertical GetTileChar Test 1", TestBoard.GetVerticalTile(2, 2), ' ');
	TestChars("Board Vertical GetTileChar Test 2", TestBoard.GetVerticalTile(1, 1), ' ');
	TestChars("Board Vertical GetTileChar Test 3", TestBoard.GetVerticalTile(5, 4), ' ');
	
	// Test the Game Board's Ability to Change a Horizontal Tile's char.
	TestBoard.ChangeHorizontalTile(2, 2, '-');
	TestBoard.ChangeHorizontalTile(1, 1, '-');
	TestBoard.ChangeHorizontalTile(4, 5, '-');
	TestChars("Board Change Horizontal SetTileChar CONTROL", TestBoard.GetHorizontalTile(3, 3), '-');
	TestChars("Board Change Horizontal SetTileChar Test 1", TestBoard.GetHorizontalTile(2, 2), '-');
	TestChars("Board Change Horizontal SetTileChar Test 2", TestBoard.GetHorizontalTile(1, 1), '-');
	TestChars("Board Change Horizontal SetTileChar Test 3", TestBoard.GetHorizontalTile(4, 5), '-');
	
	// Test the Game Board's Ability to Change a Vertical Tile's char.
	TestBoard.ChangeVerticalTile(2, 2, '|');
	TestBoard.ChangeVerticalTile(1, 1, '|');
	TestBoard.ChangeVerticalTile(5, 4, '|');
	TestChars("Board Change Vertical SetTileChar CONTROL", TestBoard.GetVerticalTile(3, 3), '|');
	TestChars("Board Change Vertical SetTileChar Test 2", TestBoard.GetVerticalTile(1, 1), '|');
	TestChars("Board Change Vertical SetTileChar Test 3", TestBoard.GetVerticalTile(5, 4), '|');
	
	// Test board ability to draw itself.
	TestBoard.DrawBoard();
	
	// Testing Player.
	Board PlayerTestBoard(5, 5);
	Player Player1( 1 , &PlayerTestBoard);


	//PlayerTestBoard.DrawBoard();

	//Test the Player's ability to change a Horizontal tile.
	Player1.HorizontalMove(1, 1);
	Player1.HorizontalMove(2, 2);
	Player1.HorizontalMove(4, 5);
	TestChars("PLAYER Change Horizontal SetTileChar CONTROL",PlayerTestBoard.GetHorizontalTile(3, 3), '-');
	TestChars("PLAYER Change Horizontal SetTileChar Test 1", PlayerTestBoard.GetHorizontalTile(2, 2), '-');
	TestChars("PLAYER Change Horizontal SetTileChar Test 2", PlayerTestBoard.GetHorizontalTile(1, 1), '-');
	TestChars("PLAYER Change Horizontal SetTileChar Test 3", PlayerTestBoard.GetHorizontalTile(4, 5), '-');

	// Test the Plyaer's Ability to get a Vertical Tile's Char.
	Player1.VerticalMove(1, 1);
	Player1.VerticalMove(2, 2);
	Player1.VerticalMove(5, 4);
	TestChars("PLAYER Change Vertical SetTileChar CONTROL", PlayerTestBoard.GetVerticalTile(3, 3), '|');
	TestChars("PLAYER Change Vertical SetTileChar Test 1", PlayerTestBoard.GetVerticalTile(2, 2), '|');
	TestChars("PLAYER Change Vertical SetTileChar Test 2", PlayerTestBoard.GetVerticalTile(1, 1), '|');
	TestChars("PLAYER Change Vertical SetTileChar Test 3", PlayerTestBoard.GetVerticalTile(5, 4), '|');

	// Test Player's Ability to Print their own name.
	Player1.PrintName();
	std::cout << std::endl;
	PlayerTestBoard.DrawBoard();

}