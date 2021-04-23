#pragma once
#include "Grid.h"
#include "Tile.h"
#include <vector>

class Player
{
public:
	//Constructor takes a Grid refrence
	Player(Grid& owner)
		:m_pOwnerGrid{ &owner }
	{
		m_PlayerX = 0;
		m_PlayerY = 0;
		isPlaying = true;

		m_playerTile = TileType::kPlayer;
	}

	//destructor 
	~Player() {}

	bool PlayingCheck()
	{
		return isPlaying;
	}

	void Loose()
	{
		isPlaying = false;
	}

	// takes a character input and moves the player
	void PlayerMove(Grid &Level, char direction)
	{
		Tile m_Player('@');

		size_t x = m_PlayerX;
		size_t y = m_PlayerY;

		switch (direction)
		{
		case'w':
			if (y - 1 >= 0)
			{
				y = y - 1;
				break;
			}
		case 's':
			if (y + 1 <= Level.GetHeight()+ 2)
			{
				y = y + 1;
				break;
			}
		case 'd':
			if (x + 1 < Level.GetWidth() + 2)
			{
				x = x + 1;
				break;
			}
		case 'a':
			if (x - 1 > 0)
			{
				x = x - 1;
				break;
			}
		case'q':
			exit(1);
		default:
			break;
		}

		if (Level.GetTile(x,y) == '.')
		{
			Level.ChangeTile(x, y, m_Player.GetContent());
			Level.ChangeTile(m_PlayerX, m_PlayerY, '.');
			SetPosition(y, x);
		}

		if (Level.GetTile(x, y) == 'X')
		{
			isPlaying = false;
		}
	}

	void SetPosition(size_t x, size_t y)
	{
		m_PlayerX = x;
		m_PlayerY = y;
	}

private:
	Grid* const m_pOwnerGrid;
	size_t m_PlayerX;
	size_t m_PlayerY;
	bool isPlaying;
	TileType m_playerTile;
};