#pragma once
#include "../gameobjects/Table.h"

class Game {

private:

	Table* _table;
public:

	static const int MAX_NUM_PLAYERS = 6;

	Game();

	void addPlayerToTable(Player& p);
	void shareOutCards();
	void retrieveCards();
	void printGame();
	bool isGameFinished();
};