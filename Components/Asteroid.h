#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "AsteroidRender.h"

class Asteroid
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	AsteroidRender render;

	int health;
	bool isAlive;
	Asteroid();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};
