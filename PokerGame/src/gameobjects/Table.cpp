#include "Table.h"

Table::Table() {
	_deck = new Deck();
	_cardsOnTable.reserve(MAX_CARDS_ON_TABLE);
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
			std::unique_ptr<Card> card = _deck->takeRandomCard();
			p->takeCard(card);
			card = _deck->takeRandomCard();
			p->takeCard(card);
		}
	}
	std::cout << '\n';
}

void Table::retrieveCards() {

	for (int i = 0; i < _players.size(); i++) {

		// Take both of player cards
		for (int j = 0; j < Player::MAX_CARDS_ON_HAND; j++) {
			Player* p = &_players[i];
			std::unique_ptr<Card> card = p->retrieveCard();
			_deck->retrieveCard(card);
		}
	}
}

void Table::addCardToTable(){
	std::unique_ptr<Card> card = _deck->takeRandomCard();
	_cardsOnTable[_cardsCounter++] = std::move(card);
}

void Table::retrieveCardsFromTable(){

	const int numCards = _cardsCounter;

	for (int i = 0; i < numCards; i++) {
		std::unique_ptr<Card> card = std::move(_cardsOnTable.at(_cardsCounter - 1));
		//_cardsOnTable.pop_back();	// No es neceseario ¿?¿?
		_deck->retrieveCard(card);
	}
	_cardsCounter = 0;
}

void Table::printDeck() {
	_deck->printAllDeck();
}

const std::vector<std::string> Table::getCardsOnTableInfo() const{

	std::vector<std::string> infoList;

	int numCards = _cardsOnTable.size();
	for (int i = 0; i < numCards; i++) {
		if (!_cardsOnTable[i])
			infoList.push_back(_cardsOnTable[i]->toString());
		else
			infoList.push_back(Card::missingCardToString());
	}

	return infoList;
}

const std::vector<Player&> Table::getPlayerList() const{
	return _players;
}
