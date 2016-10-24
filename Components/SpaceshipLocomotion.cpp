#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

//using namespace sfw;
//using sfw::getKey;

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	breakPower = 1.0f;
	turnSpeed = 2.5f;
	speed = 125.0f;
	maxSpeed = 300.0f;
}

void SpaceshipLocomotion::doThrust(float value) {vertThrust += value;}

void SpaceshipLocomotion::doTurn(float value) {horzThrust += value;}

void SpaceshipLocomotion::doStop(float value) {stopAction += value;}

void SpaceshipLocomotion::update(Transform &trans, Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThrust = vertThrust = stopAction = 0;
}
