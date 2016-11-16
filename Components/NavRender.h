#pragma once
#include "Transform.h"

class NavRender
{
public:

	NavRender(unsigned a_color = 0xfffffffff, float a_size = 2.f);

	unsigned int color;
	float size;

	void draw(Transform &navTrans, const mat3 &camera, const vec3 pointers[]);

};