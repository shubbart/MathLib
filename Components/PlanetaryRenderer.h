#pragma once
#include "Transform.h"

class PlanetaryRenderer
{
public:
	PlanetaryRenderer(unsigned a_color = 0xfffffffff, float a_size = 20.f);

	unsigned int color;
	float size;

	void draw(Transform &planetTrans, const mat3 &camera);

};
