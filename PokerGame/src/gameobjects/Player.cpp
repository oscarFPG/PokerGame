#include "Player.h"

Player::Player(std::string name, int pot) {
	_hand = new Hand();
	_role = PlayerRole::NOT_ASSIGNED;
	_name = name;
	_money = pot;
	_moneyOnTable = 0;
	_playing = true;
}

void Player::takeCard(std::unique_ptr<Card>& card) {
	_hand->takeCard(std::move(card));
}

std::unique_ptr<Card> Player::retrieveCard() {
	return _hand->retrieveCard();
}

int Player::makeForcedBet(const int bet){

	if (_money < bet) {
		_moneyOnTable = _money;
		_money = 0;
	}
	else {
		_money -= bet;
		_moneyOnTable += bet;
	}
	
	std::cout << _name << " was forced to bet " << bet << "$\n";
	std::cout << "Current " << _name << " money is " << _money << "$\n";
	std::cout << "Current " << _name << " money on table is " << _moneyOnTable << "$\n";

	return _moneyOnTable;
}

Player::Action Player::makePlay(const int minimumBet){

	Action action;

	std::cout << "--- COMANDOS ---\n";
	std::cout << "(1) - CHECK\n";
	std::cout << "(2) - RAISE\n";
	std::cout << "(3) - FOLD\n";
	std::cout << _name << " is making a decision...\n";

	int command;
	std::cin >> command;

	switch (command){
	
	case 1:
		action.bet = (minimumBet < _money) ? minimumBet : _money;
		action.restartTurn = false;
		break;

	case 2:
		
		int amount;
		std::cout << "Cantidad a apostar: ";
		std::cin >> amount;
		std::cout << "\n";

		action.bet = (amount < _money) ? amount : _money;
		action.restartTurn = true;
		break;

	case 3:
	default:
		action.bet = 0;
		action.restartTurn = false;
		break;
	}

	return action;
}

void Player::givePrize(const int amount){
	_money += amount;
}

void Player::retire(){
	_playing = false;
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