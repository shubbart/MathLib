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

Plane operator*(const mat3 & T, const Plane & P)
{
	Plane retval;
	retval.pos = (T * vec3{ P.pos.x, P.pos.y, 1 }).xy;

	retval.dir = normal(T * vec3{ P.dir.x, P.dir.y, 0 }).xy;

	return retval;
}

bool operator==(const Plane & A, const Plane & B)
{
	return A.pos == B.pos && A.dir == B.dir;
}


Hull::Hull(const vec2 * a_vertices, unsigned a_size)
{
	size = a_size;
	for (int i = 0; i < a_size; ++i)
	{
		vertices[i] = a_vertices[i];
		if (i + 1 >= a_size)
			normals[i] = perp(normal(a_vertices[i] - a_vertices[0]));
		else
		normals[i] = perp(normal(a_vertices[i] - a_vertices[i + 1]));
	}

}

Hull::Hull()
{
	size = 0;}

Hull operator*(const mat3 & T, const Hull & H)
{
	Hull retval;
	retval.size = H.size;
	for (int i = 0; i < H.size; ++i)
	{
		retval.vertices[i] = (T * vec3{ H.vertices[i].x,  H.vertices[i].y, 1 }).xy;
		retval.normals[i] = (T * vec3{ H.normals[i].x,  H.normals[i].y, 0 }).xy;
	}

	return retval;
}

bool operator==(const Hull & A, const Hull & B)
{
	return A == B;
}
