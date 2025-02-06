#pragma once
#include <string>
#include "Card.h"
#include "../logic/PlayerRole.h"
#include "../logic/Hand.h"
#include "../interfaces/PlayerGUI.h"

class Player : PlayerGUI {

public:

	static const int MAX_CARDS_ON_HAND = 2;
private:

	Hand* _hand;
	PlayerRole _role;
	std::string _name;
	unsigned int _money;
	bool _playing;
	
public:

	Player(std::string name, int pot);

	void takeCard(std::unique_ptr<Card>& card);
	std::unique_ptr<Card> retrieveCard();
	void makeForcedBet(const int bet);

	void setPlayerRole(const PlayerRole& role);
	std::string getPlayerInfo() override;
	std::vector<std::string> getCardsInfo() override;

	const PlayerRole getPlayerRole() const;
	const bool isPlaying() const;
	const std::string getPlayerName() const;
};