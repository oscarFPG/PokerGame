#pragma once
#include <vector>
#include "../gameobjects/Card.h"

class Hand{

public:
	const static int MAX_CARDS = 2;

private:
	std::unique_ptr<Card> _hand[Hand::MAX_CARDS];
	int _numCards;

public:

	Hand();

	void takeCard(std::unique_ptr<Card> c);
	std::unique_ptr<Card> retrieveCard();
	const std::vector<std::string> getCardsInfo() const;

};