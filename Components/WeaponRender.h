#pragma once
#include "Transform.h"

class WeaponRender
{
public:

	WeaponRender(unsigned a_color = 0xfffffffff, float a_size = 2.f);

	unsigned int color;
	float size;

	void draw(Transform &weaponTrans, const mat3 &camera);

};

