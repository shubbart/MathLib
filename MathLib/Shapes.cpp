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

	retval.rad = mX > mY ? mX : mY;

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

	vec3 p1 = T * vec3{ B.min().x, B.min().y, 1 };
	vec3 p2 = T * vec3{ B.min().x, B.max().y, 1 };
	vec3 p3 = T * vec3{ B.max().x, B.min().y, 1 };
	vec3 p4 = T * vec3{ B.max().x, B.max().y, 1 };

	float xPoints[4] = { p1.x, p2.x, p3.x, p4.x };
	float yPoints[4] = { p1.y, p2.y, p3.y, p4.y };

	float xMin = p1.x;
	float xMax = p1.x;
	float yMin = p1.y;
	float yMax = p1.y;

	for (int i = 1; i < 4; ++i)
	{

	if (xPoints[i] < xMin)
			xMin = xPoints[i];
	if	(xPoints[i] > xMax)
			xMax = xPoints[i];

	if (yPoints[i] < yMin)
			yMin = yPoints[i];
	if (yPoints[i] > yMax)
			yMax = yPoints[i];
	}

	AABB retval = B;

	retval.pos.x = (xMax + xMin) / 2;
	retval.pos.y = (yMax + yMin) / 2;
	retval.he.x = (xMax - xMin) / 2;
	retval.he.y = (yMax - yMin) / 2;

	return retval;
}