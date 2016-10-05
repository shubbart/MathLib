#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"

//using namespace sfw;
//using sfw::getKey;

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	speed = 7000.0f;
	maxSpeed = 10000.0f;
}

void SpaceshipLocomotion::doThrust(float value)
{
	vertThrust = value;
}

void SpaceshipLocomotion::doTurn(float value)
{
	horzThrust = value;
}

void SpaceshipLocomotion::update(Rigidbody & rigidbody, float deltaTime)
{
	//poll for input
	//apply the values to my rigidbody
	rigidbody.acceleration.x = horzThrust * speed * deltaTime;
	rigidbody.acceleration.y = vertThrust * speed * deltaTime;

	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		vec2 dir = normal(rigidbody.velocity);
		rigidbody.velocity = dir * maxSpeed;
	}
	//zero out the thrust values

	vertThrust = 0.0f;
	horzThrust = 0.0f;

}
