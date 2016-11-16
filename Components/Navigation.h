#pragma once
#include "GameState.h"
#include "Asteroid.h"
#include "Transform.h"
#include "RigidBody.h"
#include "NavRender.h"

class Navigation
{
public:

	Transform transform;
	Collider collider;
	Rigidbody rigidbody;
	NavRender render;
	
	Navigation();
	vec3 pointers[4];
	Asteroid count[4];
	void update(float deltaTime, class GameState &gs, const Asteroid asteroid[]);
	void draw(const mat3 & camera, vec3 pointers[]);
};
