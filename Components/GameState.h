#pragma once
#include "PlayerShip.h"
#include"Camera.h"
#include "Weapon.h"
#include "Asteroid.h"
#include "Navigation.h"

class GameState
{

public:
	PlayerShip player;
	Camera camera;
	Asteroid asteroid[4];
	Weapon weapon;
	Navigation navigate;

	void play();
	void update(float deltaTime);
	void draw();
};
