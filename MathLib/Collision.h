#pragma once
#include "drawShape.h"

struct  CollisionData1D
{
	bool result() const;			 // penetraionDepth > 0
	float penetrationDepth;  // How much overlap
	float collisionNormal;   // -1 or 1
	float MTV() const;				 // penetrationDepth * collisionNormal
};

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax);

struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal;

	bool result() const;
};

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel);

struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

CollisionData boxCollision(const AABB &A, const AABB &B);

struct CollisionDataSwept
{
	float entryTime, exitTime;
	vec2 collisionNormal;
	bool collides;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB&A, const vec2 &dA, const AABB &B, const vec2 &dB);

CollisionData planeBoxCollision(const Plane &P, const AABB &B);
CollisionDataSwept planeBoxCollisionSwept(const Plane &P, const vec2 Pvel, const AABB &B, const vec2 &Bvel);

CollisionData hullCollision(const Hull &A, const Hull &B);