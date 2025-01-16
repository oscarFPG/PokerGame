#pragma once
#include <random>
#include <iostream>
#include "Card.h"

class Deck {

public:

	static const int NUM_VALUES = 13;
	static const int NUM_SUITS = 4;


private:

	Card _fullDeck[Deck::NUM_SUITS][Deck::NUM_VALUES];

	void initializeDeck();

public:

	Deck();

	Card* takeRandomCard();
	void printAllDeck();
	void retrieveCard(Card& card);
};