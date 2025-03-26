#pragma once
#include <vector>
#include "Player.h"
#include "Deck.h"
#include "../logic/PlayerRole.h"


class Table {

public:

	static const int INITIAL_NUM_CARDS_ON_TABLE = 3;
	static const int MAX_PLAYERS = 6;
	static const int MAX_CARDS_ON_TABLE = 5;

private:

	struct HandInfo {
		int maxBet = 0;		// Biggets bet
		int totalBet = 0;	// Total amount of bets
	};

	int SMALL_BLIND_BET = 1;
	int BIG_BLIND_BET = SMALL_BLIND_BET * 2;

	Deck* _deck;
	std::vector<std::shared_ptr<Player>> _players;
	int _playerturn;	// Posicion en el vector que indica
	std::vector<std::unique_ptr<Card>> _cardsOnTable;
	int _cardsCounter;
	bool _isHandWinningPlayer;

	void passPlayersIndex();
	int getSmallBlindIndex() const;
	int getBigBlindIndex() const;
	int getPlayerTurnIndex() const;
	const int getRemainingPlayers() const;
	HandInfo makeForcedPlays();
	HandInfo allPlayersPlayOneHand(const int& minimumBet);
	Player* calculateHandWinningPlayer() const;

public:

	Table();

	void addPlayer(std::shared_ptr<Player>& player);
	void shareOutCards();
	void retrieveCardsFromPlayers();
	void addCardToTable();
	void retrieveCardsFromTable();
	void assignRolesToAllPlayers();
	void passTurn();
	void playFullHand();

	void printDeck();
	const std::vector<std::string> getCardsOnTableInfo() const;
	const std::vector<std::shared_ptr<Player>> getPlayerList() const;
};