#include <cstdio>
#include "GameState.h"

void main()
{
	float SCREEN_WIDTH = 1500;
	float SCREEN_HEIGHT = 1000;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfw::setBackgroundColor(BLACK);

	GameState game;
	game.play();

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		game.update(deltaTime);
		game.draw();

	}

	sfw::termContext();
}