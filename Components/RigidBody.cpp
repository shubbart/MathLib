#include "RigidBody.h"

void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	// perform euler intergration
	trans.position = trans.position + velocity*deltaTime;
}