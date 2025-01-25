#pragma once
#include "../gameobjects/Table.h"

static class GamePrinter{

private:

	std::string TABS_TOP_BOTTOM_PLAYERS;
	std::string TABS_CENTER_ROW;
	std::string TABS_BETWEEN_PLAYERS_TOP_BOTTOM;
	std::string TABS_BETWEEN_PLAYERS_CENTER;
	std::string TABS_BETWEEN_TABLE_PLAYER_LEFT;
	std::string TABS_BETWEEN_TABLE_PLAYER_RIGHT;

public:

	const static int MAX_PLAYERNAME_LENGHT = 8;

	GamePrinter(const int maxCardsOnTable);
	const void printTable(const Table* table) const;
};