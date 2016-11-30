#pragma once
#include "Transform.h"

class AIRender
{
public:
	AIRender(unsigned a_color = 0xfffffffff, float a_size = 2.f);

	unsigned int color;
	float size;

	void AIDraw(Transform &spaceshipTrans, const mat3 &camera);

};

