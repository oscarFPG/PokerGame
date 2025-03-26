#include "Player.h"

Player::Player(std::string name, int pot) {
	_hand = new Hand();
	_role = PlayerRole::NOT_ASSIGNED;
	_name = name;
	_money = pot;
	_playing = true;
}

void Player::takeCard(std::unique_ptr<Card>& card) {
	_hand->takeCard(std::move(card));
}

std::unique_ptr<Card> Player::retrieveCard() {
	return _hand->retrieveCard();
}

int Player::makeForcedBet(const int bet){

	int playersBet = 0;
	if (_money < bet) {
		playersBet = _money;
		_money = 0;
	}
	else {
		_money -= bet;
		playersBet = bet;
	}
	
	std::cout << _name << " was forced to bet " << bet << "$\n";
	std::cout << "Current money is " << _money << "\n";

	return playersBet;
}

void Player::givePrize(const int amount){
	_money += amount;
}

void Player::setPlayerRole(const PlayerRole& role){
	_role = role;
}

std::string Player::getPlayerInfo(){
	
	std::string info = _name;
	info.append(" - ");
	info.append("Pot: ");
	info.append(std::to_string(_money));
	return info;
}

std::vector<std::string> Player::getCardsInfo(){
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