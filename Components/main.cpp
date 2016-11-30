#include <cstdio>
#include "GameState.h"
#include <ctime>
#include <iostream>

void main()
{
	srand(time(NULL));

	float SCREEN_WIDTH = 1300;
	float SCREEN_HEIGHT = 900;
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