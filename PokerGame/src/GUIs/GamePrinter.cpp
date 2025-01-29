#include "GamePrinter.h"

GamePrinter::GamePrinter(const int maxCardsOnTable)
{
	TABS_TOP_BOTTOM_PLAYERS = "\t\t  ";
	TABS_CENTER_ROW = "\t";
	TABS_BETWEEN_PLAYERS_TOP_BOTTOM = "\t";
	TABS_BETWEEN_PLAYERS_CENTER = "\t";
	TABS_BETWEEN_TABLE_PLAYER_LEFT = "    ";
	TABS_BETWEEN_TABLE_PLAYER_RIGHT = "   ";
}

const void GamePrinter::printTable(const Table* table) const {

	const std::vector<std::shared_ptr<Player>> playerList = table->getPlayerList();
	const std::vector<std::string> cardsOnTable = table->getCardsOnTableInfo();
	std::string playerSymbol;

	/*
		COMO REPRESENTAR EL TABLERO

					player[0]	player[1]
		player[5]							player[2]
					player[4]	player[3]
	*/

	// Print both top players
	playerSymbol = playerList[0]->getPlayerName();
	playerSymbol.append(roleToString(playerList[0]->getPlayerRole()));
	std::cout << TABS_TOP_BOTTOM_PLAYERS << playerSymbol;
	playerSymbol.clear();

	playerSymbol = playerList[1]->getPlayerName();
	playerSymbol.append(roleToString(playerList[1]->getPlayerRole()));
	std::cout << TABS_BETWEEN_PLAYERS_TOP_BOTTOM << playerSymbol << "\n";
	playerSymbol.clear();

	// Print left side player
	playerSymbol = playerList[5]->getPlayerName();
	playerSymbol.append(roleToString(playerList[5]->getPlayerRole()));
	std::cout << TABS_CENTER_ROW << playerSymbol << TABS_BETWEEN_TABLE_PLAYER_LEFT;
	playerSymbol.clear();

	// Print table
	int numCards = cardsOnTable.size();
	for (int i = 0; i < numCards; i++) {
		std::cout << cardsOnTable[i];
	}

	// Print right side player
	playerSymbol = playerList[2]->getPlayerName();
	playerSymbol.append(roleToString(playerList[2]->getPlayerRole()));
	std::cout << TABS_BETWEEN_TABLE_PLAYER_RIGHT << playerSymbol << "\n";
	playerSymbol.clear();

	// Print both bottom players
	playerSymbol = playerList[4]->getPlayerName();
	playerSymbol.append(roleToString(playerList[4]->getPlayerRole()));
	std::cout << TABS_TOP_BOTTOM_PLAYERS << playerSymbol;
	playerSymbol.clear();

	playerSymbol = playerList[3]->getPlayerName();
	playerSymbol.append(roleToString(playerList[3]->getPlayerRole()));
	std::cout << TABS_BETWEEN_PLAYERS_TOP_BOTTOM << playerSymbol << "\n";
	playerSymbol.clear();
}

const std::string GamePrinter::roleToString(const PlayerRole& role) const{

	switch (role) {
	case PlayerRole::NOT_ASSIGNED:
		return "";
	case PlayerRole::DEALER:
		return "(D)";
	case PlayerRole::SMALL_BLIND:
		return "(b)";
	case PlayerRole::BIG_BLIND:
		return "(B)";
	default:
		return "---";
	}
}