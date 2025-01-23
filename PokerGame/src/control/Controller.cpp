#include "Controller.h"

void Controller::configureGame() {

	Player p1("Pedro[1]", 100);
	_game->addPlayerToTable(p1);

	Player p2("Pedro[2]", 100);
	_game->addPlayerToTable(p2);

	Player p3("Pedro[3]", 100);
	_game->addPlayerToTable(p3);

	Player p4("Pedro[4]", 100);
	_game->addPlayerToTable(p4);

	Player p5("Pedro[5]", 100);
	_game->addPlayerToTable(p5);

	Player p6("Pedro[6]", 100);
	_game->addPlayerToTable(p6);
}

Controller::Controller(Game* game) {
	_game = game;
}

void Controller::run() {

	// Configuracion inicial del juego
	configureGame();

	// Repartir cartas
	_game->shareOutCards();
	_game->printGame();

	// Cada jugador coge una carta
	_game->addCardToTable();

	// Devolver cartas
	_game->retrieveCards();
}