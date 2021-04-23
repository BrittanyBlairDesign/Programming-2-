#pragma once
#include "GameObject.h"

#include <string>

class Tile;

class Item :
	public GameObject
{
private:
	Tile* m_pTile;
	char m_appearance;
	std::string m_name;
	std::string m_description;

public:
	Item(char appearance, const std::string& name, const std::string& description);
	
	virtual void SetTile(Tile* pTile) final { m_pTile = pTile; }
	virtual Tile* GetTile() const final { return m_pTile; }

	virtual void Draw() const final;
	virtual void OnTouch(GameObject* pToucher) final;

	const std::string GetDescription() { return m_description; }
	const std::string GetName() { return m_name; }
};

