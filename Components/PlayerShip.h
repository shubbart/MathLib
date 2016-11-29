#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipRenderer.h"

class PlayerShip
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	SpaceshipController controller;
	SpaceshipLocomotion locomotion;
	SpaceshipRenderer render;

	int health = 100;
	bool isAlive;
	
	PlayerShip();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};
