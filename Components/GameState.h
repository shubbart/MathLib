#pragma once
#include "PlayerShip.h"
#include"Camera.h"
#include "Weapon.h"
#include "Asteroid.h"
#include "Tractor.h"
#include "RNG.h"
#include "AI.h"
#include "AIWeapon.h"

class GameState
{

public:
	PlayerShip player;
	Camera camera;
	Asteroid asteroid[150];
	Weapon weapon;
	Tractor tractor;
	RNG rng;
	AI ai;
	AIWeapon aiWeapon;
	
	float asCount = rng.RandNum(1, 10);
	float asPosX[150];
	float asPosY[150];
	float asImpulseX[150];
	float asImpulseY[150];
	void play();
	void update(float deltaTime);
	void draw();
};
