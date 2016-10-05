#pragma once
#include "RigidBody.h"

class SpaceshipLocomotion
{


	float vertThrust; //vertical movement (-1 to 1 value)
	float horzThrust; //horizontal movement (-1 to 1 value)

	float speed; //movement speed
	float maxSpeed; //max movement speed

public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);

	void update(Rigidbody &rigidbody, float deltaTime);
};
