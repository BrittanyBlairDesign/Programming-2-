#include "CollectorGame.h"

#include "Inventory.h"
#include "Item.h"
#include "PlayerCharacter.h"
#include "Tile.h"

#include <conio.h>
#include <iostream>
#include <random>
#include <time.h>

CollectorGame::CollectorGame(size_t width, size_t height)
	: m_width{ width }
	, m_height{ height }
	, m_currentMode{Mode::kWorld}
	, m_playerInventory{this}
	, m_player{&m_playerInventory}
	, m_pItems{ nullptr }
{
	int index = 0;
	for (size_t y = 0; y < height; ++y)
	{
		for (size_t x = 0; x < width; ++x)
		{
			m_ppTiles.emplace_back( new Tile{ x, y });
			++index;
		}
	}
}

CollectorGame::~CollectorGame()
{
	m_ppTiles.clear();
}

///////////////////////////////////////////////////////////////
// Plays the game.
///////////////////////////////////////////////////////////////
void CollectorGame::Play()
{
	SetTile(m_ppTiles[0], &m_player);

	constexpr size_t itemCount = 3;
	Item items[itemCount]{
		Item{'$', "Twenty-Dollar Bill", "A bill of paper money."},
		Item{'^', "Key", "A nondescript brass key."},
		Item{'&', "Sleeping Bag", "A six-foot cocoon of warm cloth."}
	};

	m_pItems = items;

	srand((unsigned)time(nullptr));

	for (size_t i = 0; i < itemCount; ++i)
	{
		while (true)
		{
			size_t randX = rand() % m_width;
			size_t randY = rand() % m_height;
			size_t index = randX + randY * m_width;
			Tile* pTile = m_ppTiles[index];
			if (pTile->GetContents() == nullptr)
			{
				SetTile(pTile, &items[i]);
				break;
			}
		}
		
	}

	while (true)
	{
		switch (m_currentMode)
		{
		case Mode::kWorld: ProcessWorldMode();	break;
		case Mode::kInventory: ProcessInventoryMode(); break;
		}
	}
}

///////////////////////////////////////////////////////////////
// Sets a Tile's content, and sets the content's Tile.
///////////////////////////////////////////////////////////////
void CollectorGame::SetTile(Tile* pTile, GameObject* pObject)
{
	if(pTile != nullptr)
		pTile->SetContents(pObject);

	if(pObject != nullptr)
		pObject->SetTile(pTile);
}

///////////////////////////////////////////////////////////////
// Draws and updates the main game.
///////////////////////////////////////////////////////////////
void CollectorGame::ProcessWorldMode()
{
	system("cls");

	int index = 0;
	for (size_t y = 0; y < m_height; ++y)
	{
		for (size_t x = 0; x < m_width; ++x)
		{
			m_ppTiles[index]->Draw();
			++index;
		}
		std::cout << std::endl;
	}

	char input = _getch();
	switch (input)
	{
	case 'w': MovePlayer(0, -1); break;
	case 's': MovePlayer(0, +1); break;
	case 'a': MovePlayer(-1, 0); break;
	case 'd': MovePlayer(+1, 0); break;
	case 'i': m_currentMode = Mode::kInventory; break;
	}
}

///////////////////////////////////////////////////////////////
// Moves the player dx (horizontal) and dy (vertical).
///////////////////////////////////////////////////////////////
void CollectorGame::MovePlayer(int dx, int dy)
{
	Tile* pCurrentTile = m_player.GetTile();
	size_t currentX = pCurrentTile->GetX();
	size_t currentY = pCurrentTile->GetY();

	int targetX = (int)currentX + dx;
	if (targetX < 0 || targetX >= (int)m_width)
		return;

	int targetY = (int)currentY + dy;
	if (targetY < 0 || targetY >= (int)m_height)
		return;

	Tile* pTargetTile = m_ppTiles[targetX + targetY * m_width];
	pTargetTile->OnEnter(&m_player);

	SetTile(pCurrentTile, nullptr);
	SetTile(pTargetTile, &m_player);
}


///////////////////////////////////////////////////////////////////////
// Places down an item according to the empty space around the player
///////////////////////////////////////////////////////////////////////
void CollectorGame::PlaceItem(Item* item)
{
	// Get Current Player Position
	Tile* playerCurrent = m_player.GetTile();

	size_t X = playerCurrent->GetX();
	size_t Y = playerCurrent->GetY();

	// Loops through untill a proper place has been found for the item to drop
	bool searching = true;
	while (searching)
	{
		// Get a random number for each time the game loops
		int randomDirection = rand() % 3;

		// Whi
		if (randomDirection == 0)
		{
			if (X + 1 < m_width)
			{
				X = X + 1;
			}
		}

		if (randomDirection == 1)
		{
			if (X - 1 >= 0)
			{
				X = X + 1;
			}
		}

		if (randomDirection == 2)
		{
			if (Y + 1 < m_height)
			{
				Y = Y + 1;
			}
		}

		if (randomDirection == 3)
		{
			if (Y - 1 >= 0)
			{
				Y = Y + 1;
			}
		}

		// Get the tile you want to replace with the item
		Tile* pTargetTile = m_ppTiles[X + Y * m_width];

		// If the tile is empty then we can place the item. otherwise we loop through again.
		if (!pTargetTile->GetContents())
		{
			SetTile(pTargetTile, item);
			searching = false;
		}
	}


}

///////////////////////////////////////////////////////////////
// Draws and executes the inventory screen.
///////////////////////////////////////////////////////////////
void CollectorGame::ProcessInventoryMode()
{
	m_playerInventory.Draw();
	m_playerInventory.ProcessInput();
}
