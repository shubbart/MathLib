#pragma once
#include "vec2.h"
#include "mat3.h"

class Transform
{
public:
	//Transform();
	Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0);

	vec2  m_position;
	vec2  m_scale;
	float m_facing;

	//void func(float param1 = 0.0f, float param2);

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	mat3 getLocalTransform() const;

	void debugDraw(const mat3 &T = mat3Identity()) const;
};

// Default constructor gets called 40 times
// Transform trans[40];