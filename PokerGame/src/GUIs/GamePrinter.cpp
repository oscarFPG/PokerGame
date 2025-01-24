#include "GamePrinter.h"

GamePrinter::GamePrinter(const int maxCardsOnTable)
{
	TABS_TOP_BOTTOM_PLAYERS = "\t\t  ";
	TABS_CENTER_ROW = "\t";
	TABS_BETWEEN_PLAYERS_TOP_BOTTOM = "\t";
	TABS_BETWEEN_PLAYERS_CENTER = "\t";
	TABS_BETWEEN_TABLE_PLAYER_LEFT = "    ";
	TABS_BETWEEN_TABLE_PLAYER_RIGHT = "   ";
	numCards = maxCardsOnTable;
}

const void GamePrinter::printTable(const Table* table) const {

	const std::vector<Player*> playerList = table->getPlayerList();
	const std::vector<std::string> cardsOnTable = table->getCardsOnTableInfo();

	/*
		COMO REPRESENTAR EL TABLERO

					player[0]	player[1]
		player[5]							player[2]
					player[4]	player[3]
	*/

	// Print both top players
	std::cout << TABS_TOP_BOTTOM_PLAYERS << playerList[0]->getPlayerName() << TABS_BETWEEN_PLAYERS_TOP_BOTTOM << playerList[1]->getPlayerName() << "\n";

	// Print left side player
	std::cout << TABS_CENTER_ROW << playerList[5]->getPlayerName() << TABS_BETWEEN_TABLE_PLAYER_LEFT;

	// Print table
	for (int i = 0; i < numCards; i++) {
		std::cout << cardsOnTable[i];
	}

	// Print right side player
	std::cout << TABS_BETWEEN_TABLE_PLAYER_RIGHT << playerList[2]->getPlayerName() << "\n";

	// Print both bottom players
	std::cout << TABS_TOP_BOTTOM_PLAYERS << playerList[4]->getPlayerName() << TABS_BETWEEN_PLAYERS_TOP_BOTTOM << playerList[3]->getPlayerName() << "\n";
}