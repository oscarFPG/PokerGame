#include "Controller.h"

void Controller::configureGame() {

	Player p1("Pedro", 100);
	_game->addPlayerToTable(p1);

	Player p2("Pedro", 100);
	_game->addPlayerToTable(p2);

	Player p3("Pedro", 100);
	_game->addPlayerToTable(p3);

	Player p4("Pedro", 100);
	_game->addPlayerToTable(p4);

	Player p5("Pedro", 100);
	_game->addPlayerToTable(p5);

	Player p6("Pedro", 100);
	_game->addPlayerToTable(p6);
}

Controller::Controller(Game* game) {
	_game = game;
}

void Controller::run() {

	// Configuracion inicial del juego
	configureGame();

	// Repartir y recoger cartas
	_game->shareOutCards();
	_game->printGame();
	_game->retrieveCards();
}