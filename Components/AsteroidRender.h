#pragma once
#include "Transform.h"
#include "sfwdraw.h"


class AsteroidRender
{
public:

	AsteroidRender();
	AsteroidRender(unsigned a_color, float a_size = 2.f);

	unsigned int color = WHITE;
	float size;

	void draw(Transform &astTrans, const mat3 &camera);

};

