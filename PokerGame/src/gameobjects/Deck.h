#pragma once
#include <random>
#include <iostream>
#include "Card.h"

class Deck {

public:

	static const int NUM_VALUES = 13;
	static const int NUM_SUITS = 4;


private:

	std::unique_ptr<Card> _fullDeck[Deck::NUM_SUITS][Deck::NUM_VALUES];

	void initializeDeck();

public:

	Deck();

	std::unique_ptr<Card> takeRandomCard();
	const void printAllDeck() const;
	void retrieveCard(std::unique_ptr<Card>& card);
};