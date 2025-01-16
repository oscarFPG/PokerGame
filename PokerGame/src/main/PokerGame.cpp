#include <iostream>
#include "../logic/Game.h"
#include "../control/Controller.h"


int main() {

	Game* game = new Game();
	Controller* controller = new Controller(game);
	controller->run();

	delete controller;
	delete game;

	return 0;
}