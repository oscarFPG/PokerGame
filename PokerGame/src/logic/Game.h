#pragma once
#include "../gameobjects/Table.h"
#include "../GUIs/GamePrinter.h"

class Game {

private:

	Table* _table;
	GamePrinter* _gamePrinter = NULL;
	bool _isPrintingOnConsole = true;

public:

	static const int MAX_NUM_PLAYERS = 6;

	Game();

	void addPlayerToTable(Player& p);
	void shareOutCards();
	void retrieveCards();
	void printGame();
	bool isGameFinished();
};