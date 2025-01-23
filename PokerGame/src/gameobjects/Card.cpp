#include "Card.h"


Card::Card() {}

Card::Card(int value, int suit) {
	_value = value;
	_suit = suit;
	_taken = false;
}

char Card::suitToChar(int suit) {

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

void Card::setTaken(bool taken) {
	_taken = taken;
}

void Card::setValue(int value) {
	_value = value;
}

void Card::setSuit(int suit) {
	_suit = suit;
}

bool Card::isTaken() {
	return _taken;
}

int Card::getValue() {
	return _value;
}

int Card::getSuit() {
	return _suit;
}

std::string Card::toString() {

	std::string info;
	info.push_back('[');
	info.append(std::to_string(_value));
	info.push_back(Card::suitToChar(_suit));
	info.push_back(']');

	return info;
}