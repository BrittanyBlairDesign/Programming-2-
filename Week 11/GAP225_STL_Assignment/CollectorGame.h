#pragma once

#include "PlayerCharacter.h"
#include "Item.h"

class Tile;

class CollectorGame
{
public:
	enum class Mode
	{
		kWorld,
		kInventory
	};

private:
	const size_t m_width;
	const size_t m_height;
	std::vector<Tile*> m_ppTiles;

	Mode m_currentMode;

	Inventory m_playerInventory;
	PlayerCharacter m_player;
	Item* m_pItems;

public:
	CollectorGame(size_t w, size_t h);
	~CollectorGame();

	void Play();
	void SetMode(Mode mode) { m_currentMode = mode; }
	void PlaceItem(Item* drop);

private:
	void SetTile(Tile* pTile, GameObject* pObject);

	void ProcessWorldMode();
	void MovePlayer(int dx, int dy);

	void ProcessInventoryMode();
};

