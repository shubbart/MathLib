#pragma once
#include "Transform.h"

class AsteroidRender
{
public:

	AsteroidRender(unsigned a_color = 0xfffffffff, float a_size = 2.f);

	unsigned int color;
	float size;

	void draw(Transform &astTrans, const mat3 &camera);

};

