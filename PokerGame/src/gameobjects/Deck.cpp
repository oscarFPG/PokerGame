#include "Deck.h"

Deck::Deck() {
	Deck::initializeDeck();
	srand(time(0));
}

void Deck::initializeDeck() {

	for (int s = 0; s < Deck::NUM_SUITS; s++) {
		for (int v = 0; v < Deck::NUM_VALUES; v++) {
			_fullDeck[s][v] = std::make_unique<Card>(s, v);
		}
	}
}

std::unique_ptr<Card> Deck::takeRandomCard() {

	int suit  = rand() % Deck::NUM_SUITS;
	int value = rand() % Deck::NUM_VALUES;

	// Mark the card as taken
	return std::move( _fullDeck[suit][value]);
}

const void Deck::printAllDeck() const{

	for (int s = 0; s < Deck::NUM_SUITS; s++) {
		for (int v = 0; v < Deck::NUM_VALUES; v++) {
			
			if (_fullDeck[s][v] != nullptr)
				std::cout << Card::missingCardToString();
			else
				std::cout << _fullDeck[s][v]->toString() << " ";
		}
	std::cout << '\n';
	}
}

void Deck::retrieveCard(std::unique_ptr<Card>& card) {
	_fullDeck[card->getSuit()][card->getValue()] = std::move(card);
}