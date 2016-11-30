#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipLocomotion.h"
#include "AIRender.h"
#include "PlayerShip.h"

class AI
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	SpaceshipLocomotion locomotion;
	AIRender render;

	int health = 100;
	bool isAlive;

	AI();

	void update(SpaceshipLocomotion & loco, class GameState & gs, float deltatime);
	void draw(const mat3 &camera);

	int RIGHT = 0;
	int LEFT = 0;
	int FORWARD = 1;
	int STOP = 0;

	void locate(Transform &Player, Transform &Enemy);
};
