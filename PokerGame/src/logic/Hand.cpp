#include "Hand.h"

Hand::Hand(){
	_numCards = 0;
}

void Hand::takeCard(std::unique_ptr<Card> c) {
	_hand[_numCards++] = std::move(c);
}

std::unique_ptr<Card> Hand::retrieveCard() {
	
	if (_numCards == 0)
		return nullptr;

	--_numCards;
	return std::move(_hand[_numCards]);
}

const std::string Hand::getCardsInfo() const
{
	return std::string();
}
