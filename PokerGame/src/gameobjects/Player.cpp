#include "Player.h"

Player::Player(std::string name, int pot) {
	_hand = new Hand();
	_role = PlayerRole::NOT_ASSIGNED;
	_name = name;
	_pot = pot;
	_playing = true;
}

void Player::takeCard(std::unique_ptr<Card>& card) {
	_hand->takeCard(std::move(card));
}

std::unique_ptr<Card> Player::retrieveCard() {
	return _hand->retrieveCard();
}

void Player::setPlayerRole(const PlayerRole& role){
	_role = role;
}

std::string Player::getPlayerInfo(){
	
	std::string info = getPlayerName();
	info.append(" - ");
	info.append("Pot: ");
	info.append(std::to_string(_pot));
	return info;
}

std::string Player::getCardsInfo() {
	return _hand->getCardsInfo();
}

const PlayerRole Player::getPlayerRole() const{
	return _role;
}

const bool Player::isPlaying() const{
	return _playing;
}

const std::string Player::getPlayerName() const{
	return _name;
}