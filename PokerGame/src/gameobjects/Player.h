#pragma once
#include <string>
#include "Card.h"
#include "../logic/PlayerRole.h"

class Player {

public:

	static const int MAX_CARDS_ON_HAND = 2;
private:

	std::unique_ptr<Card> _hand[Player::MAX_CARDS_ON_HAND];
	PlayerRole _role;
	std::string _name;
	unsigned int _pot;
	bool _playing;
	int _cardsCounter;
	
public:

	Player(std::string name, int pot);

	void takeCard(std::unique_ptr<Card>& card);
	std::unique_ptr<Card> retrieveCard();
	void setPlayerRole(const PlayerRole& role);

	const PlayerRole getPlayerRole() const;
	const bool isPlaying() const;
	const std::string getPlayerName() const;
};