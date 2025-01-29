#pragma once
#include <iostream>

class PlayerGUI {
public:

	virtual std::string getPlayerInfo() = 0;
	virtual std::string getCardsInfo() = 0;
};