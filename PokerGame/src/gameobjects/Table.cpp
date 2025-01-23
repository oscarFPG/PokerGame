#include "Table.h"

Table::Table() {
	_deck = new Deck();
	_cardsOnTable.reserve(MAX_CARDS_ON_TABLE);
	for (int i = 0; i < MAX_CARDS_ON_TABLE; i++)
		_cardsOnTable.push_back(NULL);
	_cardsCounter = 0;
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

void Table::addCardToTable(){
	Card* card = _deck->takeRandomCard();
	_cardsOnTable[_cardsCounter++] = card;
}

void Table::retrieveCardsFromTable(){

	const int numCards = _cardsCounter;

	for (int i = 0; i < numCards; i++) {
		Card* card = _cardsOnTable.at(_cardsCounter - 1);
		_cardsOnTable.pop_back();
		_deck->retrieveCard(*card);
	}
	_cardsCounter = 0;
}

void Table::printDeck() {
	_deck->printAllDeck();
}

const std::vector<Card*> Table::getCardsOnTable() const{
	return _cardsOnTable;
}

const std::vector<Player> Table::getPlayerList() const{
	return _players;
}
