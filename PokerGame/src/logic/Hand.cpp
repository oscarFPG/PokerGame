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

const std::vector<std::string> Hand::getCardsInfo() const{
	
	std::vector<std::string> cards;
	for (int i = 0; i < _numCards; i++) {

		Card* card = _hand[i].get();
		if (card != nullptr)
			cards.push_back(_hand[i]->toString());
		else
			cards.push_back(Card::missingCardToString());
	}

	return cards;
}