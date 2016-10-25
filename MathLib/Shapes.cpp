#include "Shapes.h"
#include "mat3.h"
#include "flops.h"
#include <cmath>

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval = C;

	retval.pos = (T*vec3{ C.pos.x, C.pos.y, 1 }).xy;

	float mX = magnitude(T * vec3{ 0, C.rad, 0 });
	float mY = magnitude(T * vec3{ C.rad, 0, 0 });
	
	retval.rad = mX > mY? mX : mY;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && fequals(A.rad, B.rad);
}
 
vec2 AABB::min() const
{
	return{ (pos.x - he.x),(pos.y - he.y) };
}

vec2 AABB::max() const
{
	return{ (pos.x + he.x),(pos.y + he.y) };
}

AABB operator*(const mat3 & T, const AABB & B)
{
	AABB retval = B;

	vec3 pos3 = T * vec3{ B.pos.x, B.pos.y, 1 };
	retval.pos = pos3.xy;

	return retval;
}