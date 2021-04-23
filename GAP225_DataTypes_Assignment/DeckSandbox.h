#pragma once

#include "Deck.h"

//Using Statement making PlayingCard and alias for Deck::card.
using PlayingCard = Deck::Card;

const constexpr int kChoiceShuffle = 0;
const constexpr int kChoiceDraw = 1;
const constexpr int kChoicePrintHand = 2;
const constexpr int kChoiceDiscard = 3;
const constexpr int kChoiceReturnDiscardToDraw = 4;
const constexpr int kChoiceQuit = 5;

const constexpr size_t kChoiceCount = 6;

/////////////////////////////////////////////////////////////////
// An interactive sandbox for testing the Deck class.
/////////////////////////////////////////////////////////////////
class DeckSandbox
{
private:
	Deck m_deck;
	//Using Statement making PlayingCard and alias for Deck::card.
	PlayingCard* m_pHand[52];
	

	std::string m_menuChoices[kChoiceCount]
	{
		"Shuffle the draw pile",
		"Draw a card",
		"Print your hand",
		"Discard a card",
		"Return discard pile to draw pile and shuffle",
		"Close program"
	};

public:
	DeckSandbox();
	void Run();
	
private:
	void ShowMenu();
	int GetChoice();
	void ProcessChoice(int choice);
	void Draw();
	void PrintHand();
	void Discard();
	int m_numCardsInHand;
	void ReturnDiscardToDraw();
};

