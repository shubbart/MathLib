#pragma once
#include "vec2.h"

class Transform
{
public:
	//Transform();
	Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0);

	vec2  position;
	vec2  scale;
	float facing;

	//void func(float param1 = 0.0f, float param2);

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();
};

// Default constructor gets called 40 times
// Transform trans[40];