#pragma once
#include <string>
#include <iostream>

class Card {

private:

	int _value;
	int _suit;
	bool _taken;
public:

	Card();
	Card(int value, int suit);

	char suitToChar(int suit);

	void setTaken(bool taken);
	void setValue(int value);
	void setSuit(int suit);
	bool isTaken();
	int getValue();
	int getSuit();
	std::string toString();
};