#pragma once
#include "Transform.h"
#include "Asteroid.h"
#include "PlayerShip.h"

class NavRender
{
public:

	PlayerShip player;

	NavRender(unsigned a_color = 0xfffffffff, float a_size = 2.f);
	unsigned int color;
	float size;

	void draw(Transform &navTrans, const mat3 &camera, const vec3 pointers[]);

};