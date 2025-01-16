#pragma once
#include "../logic/Game.h"
#include "../gameobjects/Player.h"
#include <iostream>

class Controller {

private:

	Game* _game;
	void configureGame();
public:

	Controller(Game* game);

	void run();
};