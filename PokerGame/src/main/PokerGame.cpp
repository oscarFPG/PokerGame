#include <iostream>
#include "../logic/Game.h"
#include "../control/Controller.h"


int main() {

	std::unique_ptr<Game> game = std::make_unique<Game>();
	std::unique_ptr<Controller> controller = std::make_unique<Controller>(std::move(game));
	controller->run();

	return 0;
}