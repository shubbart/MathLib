#pragma once
#include "Transform.h"

class SpaceshipRenderer
{
public:
	SpaceshipRenderer(unsigned a_color = 0xfffffffff, float a_size = 2.f);

	unsigned int color;
	float size;

	void shipDraw(Transform &planetTrans, const mat3 &camera);

};
