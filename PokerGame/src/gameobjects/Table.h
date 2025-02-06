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

	int SMALL_BLIND_BET = 1;
	int BIG_BLIND_BET = SMALL_BLIND_BET * 2;

	Deck* _deck;
	std::vector<std::shared_ptr<Player>> _players;
	int _playerturn;	// Posicion en el vector que indica
	std::vector<std::unique_ptr<Card>> _cardsOnTable;
	int _cardsCounter;

	int passPlayersIndex();
	int getNextPlayersIndex() const;
	int getSmallBlindIndex() const;
	int getBigBlindIndex() const;
	int getPlayerTurnIndex() const;

public:

	Table();

	void addPlayer(std::shared_ptr<Player>& player);
	void shareOutCards();
	void retrieveCards();
	void addCardToTable();
	void retrieveCardsFromTable();
	void assignRolesToAllPlayers();
	void passTurn();
	void smallBlindBets();
	void bigBlindBets();

	void printDeck();
	const std::vector<std::string> getCardsOnTableInfo() const;
	const std::vector<std::shared_ptr<Player>> getPlayerList() const;
};