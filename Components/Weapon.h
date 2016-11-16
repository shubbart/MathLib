#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "WeaponRender.h"

class Weapon
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	WeaponRender render;

	float timer;
	bool isAlive;
	int damage;

	Weapon();
	
	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};