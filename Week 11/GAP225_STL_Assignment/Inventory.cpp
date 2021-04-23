#include "Inventory.h"

#include "CollectorGame.h"

#include <conio.h>
#include <iostream>

Inventory::Inventory(CollectorGame* pGame)
	: m_pGame{pGame}
	, m_SelectionIndex(0)
{
}

///////////////////////////////////////////////////////
// This should draw the contents of the inventory.
///////////////////////////////////////////////////////
void Inventory::Draw() const
{
	system("cls");

	//TODO: Replace the body of this function.
	// It should print the contents of the user's inventory,
	// including the details of at least the currently selected item.

	std::cout << "INVENTORY MODE" << std::endl << std::endl;
	if (m_itemInvintory.size() > 0)
	{
		for (auto i = 0; i < m_itemInvintory.size(); ++i)
		{

			if (m_SelectionIndex == i)
			{
				std::cout << "->";
			}
			else
			{
				std::cout << "  ";
			}

			m_itemInvintory[i]->Draw();

			if ((i % 5) == 0 && i != 0)
			{
				std::cout << std::endl;
			}
		}

		std::cout << std::endl << std::endl;

		std::cout << m_itemInvintory[m_SelectionIndex]->GetName() << " - " << "\n \t" << m_itemInvintory[m_SelectionIndex]->GetDescription();

	}

}

///////////////////////////////////////////////////////
// Allow the user to input commands, then execute them.
///////////////////////////////////////////////////////
void Inventory::ProcessInput()
{
	//TODO: Replace the body of this function.
	// It should get user input, allowing them to select and/or drop items.

	char input = _getch();
	switch (input)
	{
	case 'w':
		MoveSelection(-5);
		break;
	case 's': 
		MoveSelection(+5);
		; break;
	case 'a': 
		MoveSelection(-1);
		break;
	case 'd':
		MoveSelection(+1);
		break;
	case 'i':
		MoveSelection(0);
		m_pGame->SetMode(CollectorGame::Mode::kWorld);
		break;
	case ' ':
		DropItem();
	}

	Draw();
}

///////////////////////////////////////////////////////
// Adds pItem to this inventory.
///////////////////////////////////////////////////////
void Inventory::AddItem(Item* pItem)
{

	//TODO: Implement this function.
	// It should add pItem to the user's inventory, causing it to get
	// drawn by Draw() and become droppable.

	m_itemInvintory.emplace_back(pItem);

}



///////////////////////////////////////////////////////
// Erases an item from the Inventory vector.
///////////////////////////////////////////////////////
void Inventory::DropItem()
{
	m_pGame->PlaceItem(m_itemInvintory[m_SelectionIndex]);

	m_itemInvintory.erase(m_itemInvintory.begin() + m_SelectionIndex);

	m_SelectionIndex = 0;
	
	
}

///////////////////////////////////////////////////////
// Moves the players Selection Arrow.
///////////////////////////////////////////////////////
void Inventory::MoveSelection(size_t move)
{
	size_t Inventorysize = m_itemInvintory.size();

	size_t newIndex = m_SelectionIndex + move;

	if (Inventorysize > newIndex && newIndex >= 0)
	{
		m_SelectionIndex = newIndex;
	}
}