#pragma once
#include <string>
#include <iostream>

class Card {

private:

	int _value;
	int _suit;
public:

	Card();
	Card(int value, int suit);

	const char suitToChar(int suit) const;

	void setValue(int value);
	void setSuit(int suit);
	const int getValue() const;
	const int getSuit() const;

	const std::string toString() const;
	const std::string static missingCardToString();
};