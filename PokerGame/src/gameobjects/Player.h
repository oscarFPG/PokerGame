#pragma once
#include <string>
#include "Card.h"

class Player {

public:

	static const int MAX_CARDS_ON_HAND = 2;
private:

	std::unique_ptr<Card> _hand[Player::MAX_CARDS_ON_HAND];
	std::string _name;
	unsigned int _pot;
	bool _playing;
	int _cardsCounter;
	
public:

	Player(std::string name, int pot);
	Player(const Player& player);

	void takeCard(std::unique_ptr<Card>& card);
	std::unique_ptr<Card> retrieveCard();

	const bool isPlaying() const;
	const std::string getPlayerName() const;
};