#include "Collision.h"
#include "vec2.h"
#include <cmath>


CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;

	float pD1 = Amax - Bmin;
	float pD2 = Bmax - Amin;

	retval.penetrationDepth = fmin(pD1, pD2);;

	retval.collisionNormal = copysignf(1, pD2 - pD1);
	
	return retval;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;

	float tL = (Amin - Bmax) / (Bvel - Avel);
	float tR = (Bmin - Amax) / (Avel - Bvel);

	retval.entryTime = fmin(tL, tR);
	retval.exitTime = fmax(tL, tR);

	retval.collisionNormal = copysignf(1, tL - tR);

	return retval;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData retval;

	CollisionData1D XCD = 
		collisionDetection1D(A.min().x, A.max().x,
							 B.min().x, B.max().x);

	CollisionData1D YCD =
		collisionDetection1D(A.min().y, A.max().y,
							 B.min().y, B.max().y);

	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal = 
					   vec2{1,0} * XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal =
						vec2{0,1} * YCD.collisionNormal;
	}
	return retval;
}

// TODO:
	// Deal with non-colliding velocities properly.
CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;

	// Discrete results in case there is no movement along the axis.
	CollisionData1D Xdis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D Ydis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);

	// Swept results along each axis
	SweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x,
		B.min().x, B.max().x, dB.x);

	SweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y,
		B.min().y, B.max().y, dB.y);
	// whether or not to use swept along that axis.
	bool xSwept = (dA.x - dB.x != 0);
	bool ySwept = (dA.y - dB.y != 0);


	// if x is sweeping and happens latest OR y is not sweeping
	if (Yres.entryTime < Xres.entryTime || xSwept && !ySwept)
	{
		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;

		retval.collides = ySwept || Ydis.result();
	}
	else if (ySwept)
	{
		retval.collisionNormal = vec2{ 0,1 } *Yres.collisionNormal;
		retval.entryTime = Yres.entryTime;
		retval.collides = xSwept || Xdis.result();
	}

	if (Yres.exitTime < Xres.exitTime || ySwept && !xSwept)

		retval.exitTime = Yres.exitTime;
	else if (xSwept)
		retval.exitTime = Xres.exitTime;

	return retval;
}

bool CollisionData1D::result() const
{
	return penetrationDepth >= 0;
}

float CollisionData1D::MTV() const
{
	return 	penetrationDepth * collisionNormal;
}

bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && entryTime <=1;
}

bool CollisionData::result() const
{
	return penetrationDepth >= 0;
}

vec2 CollisionData::MTV() const
{
	return penetrationDepth * collisionNormal;
}

bool CollisionDataSwept::result() const
{
	return entryTime >= 0 && entryTime <= 1 && collides;
}

CollisionData planeBoxCollision(const Plane & P, const AABB & B)
{
	CollisionData retval;

	vec2 b1 = { B.min().x, B.min().y };
	vec2 b2 = { B.min().x, B.max().y };
	vec2 b3 = { B.max().x, B.min().y };
	vec2 b4 = { B.max().x, B.max().y };

	vec2 p = { P.pos.x, P.pos.y };
	vec2 axis = { P.dir.x, P.dir.y };

	float ba1 = dotProd(axis, b1);
	float ba2 = dotProd(axis, b2);
	float ba3 = dotProd(axis, b3);
	float ba4 = dotProd(axis, b4);

	float Bmin = fminf(ba1, fminf(ba2, (fminf(ba3, ba4))));
	float Bmax = fmaxf(ba1, fminf(ba2, (fminf(ba3, ba4))));

	float Pmax = dotProd(p, axis);

	retval.penetrationDepth = Pmax - Bmin;
	retval.collisionNormal = P.dir;

	return retval;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const vec2 Pvel, const AABB & B, const vec2 &Bvel)
{
	CollisionDataSwept retval;

	vec2 b1 = { B.min().x, B.min().y };
	vec2 b2 = { B.min().x, B.max().y };
	vec2 b3 = { B.max().x, B.min().y };
	vec2 b4 = { B.max().x, B.max().y };

	vec2 axis = { P.dir.x, P.dir.y };

	float ba1 = dotProd(axis, b1);
	float ba2 = dotProd(axis, b2);
	float ba3 = dotProd(axis, b3);
	float ba4 = dotProd(axis, b4);

	float Bmin = fminf(ba1, fminf(ba2, (fminf(ba3, ba4))));
	float Bmax = fmaxf(ba1, fminf(ba2, (fminf(ba3, ba4))));

	float Pmax = dotProd(P.dir, P.pos);
	float pBvel = dotProd(P.dir, Bvel);
	float pPvel = dotProd(P.dir, Pvel);

	retval.entryTime = (Bmin - Pmax)/(pPvel - pBvel);
	retval.exitTime = (Bmax - Pmax) / (pPvel - pBvel);

	return retval;
}

CollisionData hullCollision(const Hull & A, const Hull & B)
{


	// Combining all the axes into a single array
	// This isn't necessary, but prevents duplicating
	// the evaluation loop
	int size = 0;
	vec2 axes[32];

	for (int j = 0; j < A.size; ++j) axes[size++] = A.normals[j];
	for (int j = 0; j < B.size; ++j) axes[size++] = B.normals[j];


	// Set up the return value
	// Since we're looking for the smallest penetration depth
	// along each axis, we can assume an infinitely large
	// penetration depth and reduce it as we discover results.

	CollisionData retval;
	retval.penetrationDepth = INFINITY;



	// This is the actual test- it's broken into two steps.
	// Find the projected min/max of each volume.
	// Determine their penetration depth.

	// The smallest of all is the final result.

	for (int j = 0; j < size; ++j)
	{
		vec2 &axis = axes[j]; // cache the axis

							  /////////////////////
							  // Evaluate the extents
							  // Start with some obnoxious values and work our way in.
		float amin = INFINITY, amax = -INFINITY;
		float bmin = INFINITY, bmax = -INFINITY;

		// Loop through A's vertices and project the points.
		for (int i = 0; i < A.size; ++i)
		{
			float proj = dotProd(axis, A.vertices[i]);
			amin = fminf(proj, amin);
			amax = fmaxf(proj, amax);
		}

		// Loop through B's vertices and project the points.
		for (int i = 0; i < B.size; ++i)
		{
			float proj = dotProd(axis, B.vertices[i]);
			bmin = fminf(proj, bmin);
			bmax = fmaxf(proj, bmax);
		}

		/////////////////////////
		// Evaluation
		// Determine the penetration depth
		float pDr, pDl, pD, H;
		pDr = amax - bmin;
		pDl = bmax - amin;

		pD = fminf(pDr, pDl);

		// The direction along the axis
		H = copysignf(1, pDl - pDr);

		// Pick the smallest one
		if (pD < retval.penetrationDepth)
		{
			retval.penetrationDepth = pD;
			retval.collisionNormal = axis * H;
		}
	}
	return retval;
}