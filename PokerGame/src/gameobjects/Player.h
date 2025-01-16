#pragma once
#include <string>
#include "Card.h"

class Player {

public:

	static const int MAX_CARDS_ON_HAND = 2;
private:

	std::string _name;
	unsigned int _pot;
	bool _playing;
	int _cardsCounter;
	Card* _hand[Player::MAX_CARDS_ON_HAND];
public:

	Player(std::string name, int pot);

	void takeCard(Card& card);
	Card* retrieveCard();

	bool isPlaying();
};