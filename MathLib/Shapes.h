
#pragma once
#include "mat3.h"

struct  Circle
{
	vec2 pos;
	float rad;

};

Circle operator*(const mat3 &T, const Circle &C);
bool operator==(const Circle &A, const Circle &B);

struct AABB
{
	vec2 pos;
	vec2 he;	// half-extents
				// x = half-width
				// y = half-height
	vec2 min() const;
	vec2 max() const;
};

AABB operator*(const mat3 &T, const AABB &B);

struct Plane
{
	vec2 pos, dir;
};

Plane operator*(const mat3 &T, const Plane &P);
bool operator==(const Plane &A, const Plane &B);

struct Ray
{

};

Ray operator*(const mat3 &T, const Ray &R);
Ray operator==(const Ray &A, const Ray &B);

struct Hull
{
	vec2 vertices[16];
	vec2 normals[16];
	unsigned int size;

	Hull(const vec2 *a_vertices, unsigned a_size);

	Hull();
};

Hull operator*(const mat3 &T, const Hull &H);
bool operator==(const Hull &A, const Hull &B);




