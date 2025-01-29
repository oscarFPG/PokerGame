#pragma once
#include <string>
#include <iostream>

class Card {

public:
	
	static const int CARD_JOKER = 11;
	static const int CARD_QUEEN = 12;
	static const int CARD_KING = 13;
	static const int CARD_AS = 14;

private:

	int _value;
	int _suit;
public:

	Card();
	Card(int suit, int value);

	const std::string valueToString(int value) const;
	const char suitToChar(int suit) const;

	void setValue(int value);
	void setSuit(int suit);
	const int getValue() const;
	const int getSuit() const;

	std::string toString() const;
	const std::string static missingCardToString();
};