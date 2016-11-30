#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "WeaponRender.h"

class AIWeapon
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	WeaponRender render;

	float timer;
	bool isAlive;
	int damage;

	AIWeapon();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};
