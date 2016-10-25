#pragma once
#include "Shapes.h"
#include "drawShape.h"

struct weapon
{
	vec2 pos;
	float rad;
	float speed;
	float dir;
	unsigned color;
};

void Shoot(const Circle &c, unsigned color);
