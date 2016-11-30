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
	AI ai[3];
	AIWeapon aiWeapon;
	
	float asCount = rng.RandNum(20, 60);
	float asPosX[60];
	float asPosY[60];
	float asImpulseX[60];
	float asImpulseY[60];

	float aiCount = rng.RandNum(1, 3);
	float aiPosX[3];
	float aiPosY[3];

	unsigned text;

	void play();
	void update(float deltaTime);
	void draw();
};
