#pragma once
#include <vector>
#include "Player.h"
#include "Deck.h"


class Table {

public:

	static const int MAX_PLAYERS = 6;
	static const int MAX_CARDS_ON_TABLE = 5;

private:

	Deck* _deck;
	std::vector<Player&> _players;
	std::vector<std::unique_ptr<Card>> _cardsOnTable;
	int _cardsCounter;

public:

	Table();

	void addPlayer(Player& p);
	void shareOutCards();
	void retrieveCards();
	void addCardToTable();
	void retrieveCardsFromTable();

	void printDeck();
	const std::vector<std::string> getCardsOnTableInfo() const;
	const std::vector<Player&> getPlayerList() const;
};