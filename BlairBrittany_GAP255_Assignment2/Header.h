#pragma once

class Grid
{
public:
	Grid(size_t W, size_t H)
		:m_width(W)
		,m_height(H)
	{
		for (size_t i = 0; i < W * H; ++i)
		{
			m_pTiles[i] = '.';

		}
	}
	~Grid()
	{
		delete[]m_pTiles;
	}

	const size_t GetHeight()
	{
		return m_height;
	}
	
	const size_t GetWidth()
	{
		return m_width;
	}

private:
	size_t m_width;
	size_t m_height;
	char* m_pTiles;
};