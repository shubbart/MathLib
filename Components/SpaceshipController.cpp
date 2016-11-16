#include "SpaceshipController.h"
#include "sfwdraw.h"


SpaceshipController::SpaceshipController(char a_CTR_LEFT, char a_CTR_RIGHT, char a_CTR_UP, char a_CTR_DOWN, char a_CTR_BREAK)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_UP;
	CTR_DOWN = a_CTR_DOWN;
	CTR_BREAK = a_CTR_BREAK;
}

void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput -= sfw::getKey(CTR_RIGHT);
	hInput += sfw::getKey(CTR_LEFT);

	float vInput = 0.0f;
	vInput += sfw::getKey(CTR_UP);
	vInput -= sfw::getKey(CTR_DOWN);

	float bInput = sfw::getKey(CTR_BREAK);

	loco.doStop(bInput);
	loco.doTurn(hInput);
	loco.doThrust(vInput);
}
  