#pragma once
#include "Grid.h"


enum class TileType:char
{
	kPlayer = '@',
	kExit = 'X',
	kWall = '#',
	kEmpty = '.',
};

class Tile
{
public:
	//defalut constructor
	Tile(char Type)
	{
		switch (Type)
		{
		case '@':
			m_tileType = TileType::kPlayer;
			break;
		case 'X':
			m_tileType = TileType::kExit;
			break;
		case '#':
			m_tileType = TileType::kWall;
			break;
		case '.':
			m_tileType = TileType::kEmpty;
			break;
		default:
			m_tileType = TileType::kEmpty;
			break;
		}
	}
	//returns the tiles content
	const char GetContent()
	{
		switch (m_tileType)
		{
		case  TileType::kPlayer:
			return '@';
			break;
		case  TileType::kExit:
			return 'X';
			break;
		case  TileType::kWall:
			return '#';
			break;
		case  TileType::kEmpty:
			return '.';
			break;
		default:
			return '.';
			break;
		}
	}

	void SetTile(char Type)
	{
		switch (Type)
		{
		case '@':
			m_tileType = TileType::kPlayer;
			break;
		case 'X':
			m_tileType = TileType::kExit;
			break;
		case '#':
			m_tileType = TileType::kWall;
			break;
		case '.':
			m_tileType = TileType::kEmpty;
			break;
		default:
			m_tileType = TileType::kEmpty;
			break;
		}
	}
	//Prints tile
	void Print()
	{
		switch (m_tileType)
		{
		case  TileType::kPlayer:
			std::cout << '@';
			break;
		case  TileType::kExit:
			std::cout << 'X';
			break;
		case  TileType::kWall:
			std::cout << '#';
			break;
		case  TileType::kEmpty:
			std::cout << '.';
			break;
		default:
			std::cout << '.';
			break;
		}
	}

private:
	TileType m_tileType;
	int m_x = 0, m_y = 0;
	//Grid* const m_pOwnerGrid;
};


