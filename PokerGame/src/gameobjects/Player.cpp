#include "Player.h"

Player::Player(std::string name, int pot) {
	_name = name;
	_pot = pot;
	_cardsCounter = 0;
	_playing = true;
}

Player::Player(const Player& player){

}

void Player::takeCard(std::unique_ptr<Card>& card) {

	if (_cardsCounter < Player::MAX_CARDS_ON_HAND)
		_hand[_cardsCounter++] = std::move(card);
}

std::unique_ptr<Card> Player::retrieveCard() {

	if (_cardsCounter == 0)
		return nullptr;

	return std::move(_hand[--_cardsCounter]);
}

const bool Player::isPlaying() const{
	return _playing;
}

const std::string Player::getPlayerName() const{
	return _name;
}
