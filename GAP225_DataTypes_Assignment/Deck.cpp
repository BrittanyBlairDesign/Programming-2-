#include "Deck.h"

#include <random>

////////////////////////////////////////////////////////////////////////////////////////
/// I couldnt get the Using statement for CardPile = Card**  to work in the Deck.cpp ///
/// file So I added it to the Public portion of the Deck.h File so it was defind	 ///
/// in the context im usign it in.													 ///
////////////////////////////////////////////////////////////////////////////////////////
Deck::Deck()
	: m_pAllCards{ nullptr }
	, m_drawPileSize{ 0 }
	, m_pDrawPile{ nullptr }
	, m_discardPileSize{ 0 }
	, m_pDiscardPile{ nullptr }
{
	CreateCards();
	for (size_t i = 0; i < kNumFaceValues * kNumSuits; ++i)
	{
		AddToDrawPile(m_pAllCards[i]);
	}
}

Deck::~Deck()
{
	for (size_t i = 0; i < kNumFaceValues * kNumSuits; ++i)
	{
		delete m_pAllCards[i];
	}
}

/////////////////////////////////////////////////////////////////
// Creates the unique cards in a standard deck.
/////////////////////////////////////////////////////////////////
void Deck::CreateCards()
{
	size_t index = 0;
	for (size_t face = 0; face < kNumFaceValues; ++face)
	{
		for (size_t suit = 0; suit < kNumSuits; ++suit)
		{
			// face values start at 1, so we increase by 1 before passing
			m_pAllCards[index] = new Card{ face + 1, suit };

			++index;	// move to next card
		}
	}
}

/////////////////////////////////////////////////////////////////
// Adds the given pCard to the given ppPile.
// pileSize is needed to know where the card
// belongs; it will be incremented.
/////////////////////////////////////////////////////////////////
void Deck::AddCardToPile(Card* pCard, CardPile ppPile, size_t& pileSize)
{
	ppPile[pileSize] = pCard;
	++pileSize;
}

/////////////////////////////////////////////////////////////////
// Randomizes the order of elements in ppPile.
/////////////////////////////////////////////////////////////////
void Deck::Shuffle(CardPile ppPile, size_t pileSize)
{
	// Simple Fisher-Yates shuffle
	// We swap each card with some other randomly picked card.
	for (size_t i = 0; i < pileSize; ++i)
	{
		// Pick another random card
		// As i increases, we will exclude cards we already swapped
		size_t randomIndex = i + rand() % (pileSize - i);

		// Do a simple swap of the two card pointers
		Card* pTemp = ppPile[i];
		ppPile[i] = ppPile[randomIndex];
		ppPile[randomIndex] = pTemp;
	}
}

/////////////////////////////////////////////////////////////////
// Draws a card from ppPile. pileSize is needed
// to know where the card is; it will be
// decremented.
/////////////////////////////////////////////////////////////////
Deck::Card* Deck::DrawCard(CardPile ppPile, size_t& pileSize)
{
	if (pileSize == 0)
		return nullptr;

	--pileSize;
	return ppPile[pileSize];
}
