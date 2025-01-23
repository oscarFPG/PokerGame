#include "Game.h"

Game::Game() {

	if (_isPrintingOnConsole)
		_gamePrinter = new GamePrinter();

	_table = new Table();
}

void Game::addPlayerToTable(Player& p) {
	_table->addPlayer(p);
}

void Game::shareOutCards() {
	_table->shareOutCards();
}

void Game::retrieveCards() {
	_table->retrieveCards();
}

void Game::printGame() {
	if(_isPrintingOnConsole)
		_gamePrinter->printTable(_table);
}

bool Game::isGameFinished() {
	return false;
}