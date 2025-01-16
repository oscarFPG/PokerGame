#pragma once
#include <vector>
#include "Player.h"
#include "Deck.h"


class Table {

private:

	Deck* _deck;
	std::vector<Player> _players;
public:

	static const int MAX_PLAYERS = 6;

	Table();

	void addPlayer(Player& p);
	void shareOutCards();
	void retrieveCards();
	void printDeck();
	void printTable();
};