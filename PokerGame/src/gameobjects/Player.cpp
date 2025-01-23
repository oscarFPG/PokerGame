#include "Player.h"

Player::Player(std::string name, int pot) {
	_name = name;
	_pot = pot;
	_cardsCounter = 0;
	_playing = true;
}

void Player::takeCard(Card& card) {

	if (_cardsCounter < Player::MAX_CARDS_ON_HAND)
		_hand[_cardsCounter++] = &card;
}

Card* Player::retrieveCard() {

	Card* card = _hand[--_cardsCounter];
	_hand[_cardsCounter] = nullptr;
	return card;
}

bool Player::isPlaying() {
	return _playing;
}

const std::string Player::getPlayerName() const{
	return _name;
}
