#include "Controller.h"

void Controller::configureGame() {

	std::shared_ptr<Player> p1 = std::make_shared<Player>("Pedro[1]", 100);
	_game->addPlayerToTable(p1);
	
	std::shared_ptr<Player> p2 = std::make_shared<Player>("Pedro[2]", 100);
	_game->addPlayerToTable(p2);

	std::shared_ptr<Player> p3 = std::make_shared<Player>("Pedro[3]", 100);
	_game->addPlayerToTable(p3);

	std::shared_ptr<Player> p4 = std::make_shared<Player>("Pedro[4]", 100);
	_game->addPlayerToTable(p4);

	std::shared_ptr<Player> p5 = std::make_shared<Player>("Pedro[5]", 100);
	_game->addPlayerToTable(p5);

	std::shared_ptr<Player> p6 = std::make_shared<Player>("Pedro[6]", 100);
	_game->addPlayerToTable(p6);

	std::cout << "Asignando roles a los jugadores...\n";
	_game->assignRolesToAllPlayers();
}

Controller::Controller(std::unique_ptr<Game> game) {
	_game = std::move(game);
}

void Controller::run() {

	configureGame();
	
	std::cout << "Comienza la partida!\n";
	int i = 0;
	while (i == 0 && !_game->isGameFinished()) {
		_game->playHand();
		_game->passTurn();
		++i;
	}

	std::cout << "Fin de la partida!\n";
}