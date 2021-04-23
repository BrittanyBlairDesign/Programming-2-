#pragma once
/*
	Brittany Blair
	grid header file 
*/
#include <iostream>
#include <vector>
#include "Tile.h"

class Grid
{
public:
	Grid(size_t W, size_t H)
		:m_width(W)
		, m_height(H)
	{
		for (size_t i = 0; i < W; ++i)
		{
			for (size_t j = 0; j < H; ++j)
			{
				m_pTiles[i][j] = '.';
			}
		}
	}
	~Grid()
	{
		delete[]m_pTiles;
	}

	void DrawGrid()
	{
		Tile wall('#');

		for (int i = 0; i < m_width + 2; ++i)
		{
			wall.Print();
			std::cout << ' ';
		}
		std::cout << std::endl;
		for (int i = 0; i < m_width; i++) {
			for (int j = 0; j < m_height; j++) {
				std::cout << m_pTiles[i][j] << ' ';
			}
			std::cout << '\n';
		}
		for (int i = 0; i < m_width + 2; ++i)
		{
			wall.Print();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}

	char GetTile(size_t x, size_t y)
	{
		return m_pTiles[x][y];
	}

	void ChangeTile(size_t x, size_t y, char newChar)
	{
		m_pTiles[x][y] = newChar;
	}

	const size_t GetHeight()
	{
		return m_height;
	}

	const size_t GetWidth()
	{
		return m_width;
	}

	std::string PrintMaze()
	{
		for (size_t i = 0; i < m_width; ++i)
		{
			for (size_t j = 0; j < m_height; ++j)
			{
				m_pTiles[i][j] = '.';
			}
		}
	}

private:
	size_t m_width;
	size_t m_height;
	char** m_pTiles;
};