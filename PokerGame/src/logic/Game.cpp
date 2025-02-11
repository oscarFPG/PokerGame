#include "Game.h"

Game::Game() {

	if (_isPrintingOnConsole)
		_gamePrinter = new GamePrinter(Table::MAX_CARDS_ON_TABLE);

	_table = new Table();
}

void Game::addPlayerToTable(std::shared_ptr<Player>& p) const{
	_table->addPlayer(p);
}

void Game::shareOutCards() {
	_table->shareOutCards();
}

void Game::retrieveCards() {
	_table->retrieveCards();
}

void Game::addCardToTable(){
	_table->addCardToTable();
}

void Game::retrieveCardsFromTable(){
	_table->retrieveCardsFromTable();
}

void Game::assignRolesToAllPlayers(){
	_table->assignRolesToAllPlayers();
}

void Game::passTurn(){
	_table->passTurn();
}

void Game::playRound(){

	bool roundFinished = false;
	while (!roundFinished) {

		std::cout << "Small blind bets...\n";
		_table->smallBlindBets();
		std::cout << "\n";

		std::cout << "Big blind bets...\n";
		_table->bigBlindBets();
		std::cout << "\n";

		system("pause");
	}
}

void Game::printGame() {
	if(_isPrintingOnConsole)
		_gamePrinter->printTable(_table);
}

bool Game::isGameFinished() {
	return false;
}