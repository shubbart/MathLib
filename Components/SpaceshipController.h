#pragma once
#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

class SpaceshipController
{
public:
	char CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	SpaceshipController(char CTR_LEFT = 'A', char CTR_RIGHT = 'D', char CTR_UP = 'W', char CTR_DOWN = 'S', char CTR_BREAK = ' ');

	void update(SpaceshipLocomotion &loco);
};
