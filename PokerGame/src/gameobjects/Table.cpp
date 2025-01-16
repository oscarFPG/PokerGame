#include "Table.h"

Table::Table() {
	_deck = new Deck();
}

void Table::addPlayer(Player& p) {

	if (_players.size() == MAX_PLAYERS)
		return;

	_players.push_back(p);
}

void Table::shareOutCards() {

	for (int i = 0; i < _players.size(); i++) {

		Player* p = &_players[i];
		if (p->isPlaying()) {

			// Take two cards from the deck and give it to the player
			Card* card = _deck->takeRandomCard();
			p->takeCard(*card);
			card = _deck->takeRandomCard();
			p->takeCard(*card);
		}
	}
	std::cout << '\n';
}

void Table::retrieveCards() {

	for (int i = 0; i < _players.size(); i++) {

		// Take both of player cards
		for (int j = 0; j < Player::MAX_CARDS_ON_HAND; j++) {
			Player* p = &_players[i];
			Card* card = p->retrieveCard();
			_deck->retrieveCard(*card);
		}
	}
}

void Table::printDeck() {
	_deck->printAllDeck();
}

void Table::printTable() {

	// Print both top players

	// Print left side player

	// Print table

	// Print right side player

	// Print both bottom players

}