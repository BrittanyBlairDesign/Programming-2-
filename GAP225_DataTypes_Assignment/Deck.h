#pragma once

#include <assert.h>
#include <string>

const constexpr int kNumFaceValues = 13;	// There are 13 unique card values, including Ace, Jack, Queen, King
const constexpr int kNumSuits = 4;		// There are 4 suits

/////////////////////////////////////////////////////////////////
// Enumerations for Playing card deck : FaceNames & Suit Names
/////////////////////////////////////////////////////////////////
//Enum Class For Card Names : Values 1-13
enum class FaceNames
{
	kAce = 1,
	kTwo = 2,
	kThree = 3,
	kFour = 4,
	kFive = 5,
	kSix = 6,
	kSeven = 7,
	kEight = 8,
	kNine = 9,
	kTen = 10,
	kJack = 11,
	kQueen = 12,
	kKing = 13,
	kDefault
};

//Enum Class for Suit names : Valuses 0-3
enum class SuitNames
{
	kClubs,
	kDiamonds,
	kHearts,
	kSpades,
	kDefault
};

/////////////////////////////////////////////////////////////////
// A standard playing card deck implementation.
/////////////////////////////////////////////////////////////////
class Deck
{
public:
	
	/////////////////////////////////////////////////////////////////
	// A playing card implementation.
	/////////////////////////////////////////////////////////////////
	class Card
	{
	private:
		size_t m_faceValue;
		size_t m_suit;

		static const int m_minFaceValue = 1;
		static const int m_maxFaceValue = 13;
		FaceNames m_faceNames = FaceNames::kDefault;
		//std::string m_faceNames[kNumFaceValues]{ "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

		static const int m_minSuitValue = 0;
		static const int m_maxSuitValue = 3;
		SuitNames m_suitNames = SuitNames::kDefault;
		//std::string m_suitNames[kNumSuits]{ "Clubs", "Diamonds", "Hearts", "Spades" };

	public:
		Card(size_t faceValue, size_t suit)
			: m_faceValue{ faceValue }
			, m_suit{suit}
		{
			assert(faceValue >= m_minFaceValue && faceValue <= m_maxFaceValue);
			assert(suit >= m_minSuitValue && suit <= m_maxFaceValue);

			//Set Card Face Name
			switch (faceValue)
			{
			case 1:
				m_faceNames = FaceNames::kAce;
					break;
			case 2:
				m_faceNames = FaceNames::kTwo;
					break;
			case 3:
				m_faceNames = FaceNames::kThree;
					break;
			case 4:
				m_faceNames = FaceNames::kFour;
					break;
			case 5:
				m_faceNames = FaceNames::kFive;
					break;
			case 6:
				m_faceNames = FaceNames::kSix;
					break;
			case 7:
				m_faceNames = FaceNames::kSeven;
					break;
			case 8:
				m_faceNames = FaceNames::kEight;
					break;
			case 9:
				m_faceNames = FaceNames::kNine;
					break;
			case 10:
				m_faceNames = FaceNames::kTen;
					break;
			case 11:
				m_faceNames = FaceNames::kJack;
					break;
			case 12:
				m_faceNames = FaceNames::kQueen;
					break;
			case 13:
				m_faceNames = FaceNames::kKing;
					break;
			default:
				m_faceNames = FaceNames::kDefault;
			}

			// Set Card Suit
			switch (suit)
			{
			case 0:
				m_suitNames = SuitNames::kClubs;
				break;
			case 1:
				m_suitNames = SuitNames::kDiamonds;
				break;
			case 2:
				m_suitNames = SuitNames::kHearts;
				break;
			case 3:
				m_suitNames = SuitNames::kSpades;
				break;
			default:
				m_suitNames = SuitNames::kDefault;
				break;
			}
		}

		const size_t GetFaceValue() { return m_faceValue; }
		const size_t GetSuit() { return m_suit; }

		/////////////////////////////////////////////////////////////////
		// Returns this card's name in the form "(FaceValue) of (Suit)s"
		/////////////////////////////////////////////////////////////////
		std::string GetName()
		{
			return GetFaceName() + " of " + GetSuitName();
		}

	private:
		/////////////////////////////////////////////////////////////////
		// Converts this card's face value to a word from m_faceNames.
		/////////////////////////////////////////////////////////////////
		std::string GetFaceName()
		{
			switch (m_faceNames)
			{
			case FaceNames::kAce:
				return "Ace";
				break;
			case FaceNames::kTwo:
				return "Two";
				break;
			case FaceNames::kThree:
				return "Three";
				break;
			case FaceNames::kFour:
				return "Four";
				break;
			case FaceNames::kFive:
				return "Five";
				break;
			case FaceNames::kSix:
				return "Six";
				break;
			case FaceNames::kSeven:
				return "Seven";
				break;
			case FaceNames::kEight:
				return "Eight";
				break;
			case FaceNames::kNine:
				return "Nine";
				break;
			case FaceNames::kTen:
				return "Ten";
				break;
			case FaceNames::kJack:
				return "Jack";
				break;
			case FaceNames::kQueen:
				return "Queen";
				break;
			case FaceNames::kKing:
				return "King";
				break;
			default:
				return "Error";
			}
			
			//return m_faceNames[m_faceValue - 1];
		}

		/////////////////////////////////////////////////////////////////
		// Converts this card's suit value to a word from m_suitNames.
		/////////////////////////////////////////////////////////////////
		std::string GetSuitName()
		{
			switch (m_suitNames)
			{
			case SuitNames::kClubs:
				return "Clubs";
				break;
			case SuitNames::kDiamonds:
				return "Diamonds";
				break;
			case SuitNames::kHearts:
				return "Hearts";
				break;
			case SuitNames::kSpades:
				return "Spades";
				break;
			default:
				return "Default";
			}
		}
	};

private:
	// All cards are stored here, regardless of where they are
	Card* m_pAllCards[kNumFaceValues * kNumSuits];

	// Draw pile
	size_t m_drawPileSize;
	Card* m_pDrawPile[kNumFaceValues * kNumSuits];
	
	// Discard pile
	size_t m_discardPileSize;
	 Card* m_pDiscardPile[kNumFaceValues * kNumSuits];

public:
	Deck();
	~Deck();

	// Using Cardpile in place of Card**
	using CardPile = Card**;

	// Place a card on top of the main pile.
	void AddToDrawPile(Card* pCard) { AddCardToPile(pCard, m_pDrawPile, m_drawPileSize); }

	// Shuffle the main pile.
	void ShuffleDrawPile() { Shuffle(m_pDrawPile, m_drawPileSize); }

	// Draw from the main pile.
	Card* DrawFromDrawPile() { return DrawCard(m_pDrawPile, m_drawPileSize); }

	// Place a card on top of the discard pile.
	void AddToDiscardPile(Card* pCard) { AddCardToPile(pCard, m_pDiscardPile, m_discardPileSize); }
	
	// Shuffle the discard pile.
	void ShuffleDiscardPile() { Shuffle(m_pDiscardPile, m_discardPileSize); }
	
	// Draw from the discard pile.
	Card* DrawFromDiscardPile() { return DrawCard(m_pDiscardPile, m_discardPileSize); }

private:
	void CreateCards();
	void AddCardToPile(Card* pCard, Card** ppPile, size_t& pileSize);
	void Shuffle(Card** ppPile, size_t pileSize);
	Card* DrawCard(Card** ppPile, size_t& pileSize);
};