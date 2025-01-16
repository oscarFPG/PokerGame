#include "Deck.h"

Deck::Deck() {
	Deck::initializeDeck();
	srand(time(0));
}

Card* Deck::takeRandomCard() {

	int suit = rand() % Deck::NUM_SUITS;
	int value = rand() % Deck::NUM_VALUES;

	// Mark the card as taken
	Card* card = &_fullDeck[suit][value];
	card->setTaken(true);
	return card;
}

void Deck::printAllDeck() {

	for (int i = 0; i < Deck::NUM_SUITS; i++) {
		for (int j = 0; j < Deck::NUM_VALUES; j++) {
			Card* card = &_fullDeck[i][j];
			card->print();
		}
	std::cout << '\n';
	}
}

void Deck::retrieveCard(Card& card) {
	card.setTaken(false);
}

void Deck::initializeDeck() {

	for (int i = 0; i < Deck::NUM_SUITS; i++) {
		for (int j = 0; j < Deck::NUM_VALUES; j++) {
			Card* card = &_fullDeck[i][j];
			card->setSuit(i);
			card->setValue(j);
			card->setTaken(false);
		}
	}
}