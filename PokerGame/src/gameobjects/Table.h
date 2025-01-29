#pragma once
#include <vector>
#include "Player.h"
#include "Deck.h"
#include "../logic/PlayerRole.h"


class Table {

public:

	static const int MAX_PLAYERS = 6;
	static const int MAX_CARDS_ON_TABLE = 5;

private:

	Deck* _deck;
	std::vector<std::shared_ptr<Player>> _players;
	int _playerturn;	// Posicion en el vector que indica
	std::vector<std::unique_ptr<Card>> _cardsOnTable;
	int _cardsCounter;

public:

	Table();

	void addPlayer(std::shared_ptr<Player>& player);
	void shareOutCards();
	void retrieveCards();
	void addCardToTable();
	void retrieveCardsFromTable();
	void assignRolesToAllPlayers();
	void passTurn();

	void printDeck();
	const std::vector<std::string> getCardsOnTableInfo() const;
	const std::vector<std::shared_ptr<Player>> getPlayerList() const;
};