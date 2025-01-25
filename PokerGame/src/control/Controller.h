#pragma once
#include "../logic/Game.h"
#include "../gameobjects/Player.h"
#include <iostream>

class Controller {

private:

	std::unique_ptr<Game> _game;
	void configureGame();

public:

	Controller(std::unique_ptr<Game> game);

	void run();
};