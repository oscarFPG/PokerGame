#include "Card.h"


Card::Card() {}

Card::Card(int value, int suit) {
	_value = value;
	_suit = suit;
}

const char Card::suitToChar(int suit) const {

	switch (suit) {
	case 0:
		return 'P';	// Picas
	case 1:
		return 'T';	// Treboles
	case 2:
		return 'C';	// Corazones
	case 3:
		return 'D';	// Diamantes
	default:
		return 'x';
	}
}

void Card::setValue(int value) {
	_value = value;
}

void Card::setSuit(int suit) {
	_suit = suit;
}

const int Card::getValue() const {
	return _value;
}

const int Card::getSuit() const {
	return _suit;
}

const std::string Card::toString() const {

	std::string info;
	info.push_back('[');
	info.append(std::to_string(_value));
	info.push_back(Card::suitToChar(_suit));
	info.push_back(']');

	return info;
}

const std::string Card::missingCardToString(){
	return "[xx]";
}
