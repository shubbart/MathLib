#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
#include <cmath>
#include "Shapes.h"
#include "Collision.h"

int main()
{
	//Unit Test
	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);

	assert(test_quad(0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);

	assert(quad(1, 0, 0).roots == 1);
	assert(quad(1, -2, 0).roots == 2);
	assert(quad(1, 0, 4).roots == 0);

	assert(lerp(1, 0, 0) == 1);
	assert(lerp(2, -2, 0) == 2);
	assert(lerp(1, 2, 4) == 5);

	assert(inner({ 1,1,0 }, { -1,1,0 }) == 0);
	assert(inner({ 1,1,1 }, { 1,1,1 }) == 3);

	/*assert(point_plane_distance({ 0,0,1,0 }, { 0,0,0 }) == 0);
	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,1 }) == 1);*/

	assert(bezier(0, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 0);
	assert(bezier(1, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 3);
	assert(bezier(0.5f, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 1.5);

	//////////////////////////////////////
	// Vector2 Tests
	assert((vec2{ 0,0 } == vec2{ 0, 0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	assert((vec2{ 1,1 } *( 2) == vec2{ 2,2 }));
	assert(((1) *vec2 { 2, 2 } == vec2{ 2,2 }));

	assert((vec2{ 2,2 } /(2) == vec2{ 1,1 }));
	assert(((4) /vec2 { 2, 2 } == vec2{ 2,2 }));

	assert((-vec2{ 1,2 } == vec2{ -1,-2 }));

	assert((vec2{ 1,1 } +vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } -vec2{ -1,0 } == vec2{ 2,1 }));
	assert((vec2{ 3,3 } / (3) == vec2{ 1,1 }));
	assert((vec2{ 2,2 } *(2) == vec2{ 4,4 }));
	
	vec2 var = { 4,0 };
	var += vec2{ -3,1 };
	assert((var == vec2{ 1,1 }));

	vec2 var1 = { 5,0 };
	var1 += vec2{ -2,1 };
	assert((var1 != vec2{ 1,6 }));

	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert(fequals(angleBetween(vec2{ 1,0 }, vec2{ 0,1 }),
		deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
		deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
		angle(vec2{ 1,1 })));

	//assert((magnitude(vec2{ 2, 2}) == sqrt(8)));

	//////////////////////////////////////
	// Vector3 Tests
	assert((vec3{ 0, 0,0 } == vec3{ 0, 0, 0 }));
	assert((vec3{ 1, 0, 0 } == vec3{ 1, 0, 0 }));

	assert((vec3{ 1,1,1 } *(2) == vec3{ 2,2,2 }));
	assert(((1) *vec3 { 2, 2, 2 } == vec3{ 2,2,2 }));

	assert((vec3{ 2,2,2 } / (2) == vec3{ 1,1,1 }));
	assert(((4) / vec3{ 2, 2, 2 } == vec3{ 2,2,2 }));

	assert((-vec3{ 1,2,3 } == vec3{ -1,-2,-3 }));

	assert((vec3{ 1,1,1 } +vec3{ -1,0,-1 } == vec3{ 0,1,0 }));
	assert((vec3{ 1,1,1 } -vec3{ -1,0,1 } == vec3{ 2,1,0 }));
	assert((vec3{ 3,3,3 } / (3) == vec3{ 1,1,1 }));
	assert((vec3{ 2,2,2 } *(2) == vec3{ 4,4,4 }));

	vec3 var2 = { 4,0,1 };
	var2 += vec3{ -3,1,0 };
	assert((var2 == vec3{ 1,1,1 }));

	vec3 var3 = { 5,0,3 };
	var3 += vec3{ -2,1,5 };
	assert((var3 != vec3{ 1,6,33 }));

	//assert((magnitude(vec3{2,2,2}) == sqrt(12)));

	assert((crossProd(vec3{ 1,0,0 }, vec3{ 0,1,0 })
									== vec3{ 0,0,1 }));


	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 1), 124));
	assert(fequals(lerp(1, 1, 1), 1));

	assert(fequals(quadBezier(0, 0, 1, 0), 0));
	assert(fequals(quadBezier(0, 0, 1, 1), 1));

	assert(fequals(HermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(HermiteSpline(15, 40, 21, 10, 1), 21));

	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));

	//////////////////////////////////////////////////////////
	//////// Matrix Tests

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,2,1 };
	vec2 v0 = vec2{ 1,0 };
	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI*-1 == -mI);

	assert(mI * mI == mI);
	assert((mat2{ 1,2,3,4 }) * mI == (mat2{ 1,2,3,4 }));

	assert(mI * v0 == v0);
	assert((t0 * v0 == vec2{ 4,2 }));

	mat2 test1 = mat2{1,2,3,4};
	assert(determinant(test1) == -2);

	assert(transpose(mI) == mI);
	assert(inverse(mI) == mI);

	assert(t0*inverse(t0) == mI);

	mat3 M0 = { 0,0,0,0,0,0,0,0,0 };
	mat3 MI = mat3Identity();
	mat3 T0 = mat3{ 9,8,7,6,5,4,3,2,1 };
	vec3 V0 = vec3{ 1,1,1 };

	assert(M0 == M0);
	assert(MI * 2 == 2 * MI);
	assert(MI + M0 == MI);
	assert(MI - MI == M0);
	assert(MI*-1 == -MI);

	assert(transpose(MI) == MI);
	assert(inverse(MI) == MI);

	assert(MI * MI == MI);
	assert((mat3{ 1,2,3,4,5,6,7,8,9 }) * MI == (mat3{ 1,2,3,4,5,6,7,8,9 }));

	mat3 Test1 = mat3{ 1,2,3,4,5,6,7,8,9 };
	assert(determinant(Test1) == 0);

	assert(MI * V0 == V0);
	//assert((T0 * V0 == vec3{ 24,15,6 }));

	vec3 j = { 2,5,1 };
	assert((scale(5, 1) * j == vec3{ 10,5,1 }));

	assert((translate(0, 3) * j == vec3{ 2,8,1 }));

	//assert((rotate(deg2rad(90)) * j == vec3{ -5,2,1 }));

	/*mat3 S = scale(2, 1);
	mat3 T = translate(4, 3);
	mat3 R = rotate(deg2rad(90));

	mat3 RES = { 0,-1,0, 2,0,0, 4,3,1 };

	assert((T*R*S == RES));*/

	/*vec3 test = rotate(deg2rad(-90)) * translate(10, 0) *
		rotate(deg2rad(45)) * translate(4, 0) *
		rotate(deg2rad(45)) * translate(-6, 0) *
		translate(6, 4) * vec3 { 0, 0, 1 };

	assert((test == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2), 1 }));*/

	///////////////////////////////////////////////////////////////
	//////////// Shapes

	/*Circle c = { 0, 0, 5 };
	assert((translate(4, 0) * c == Circle{ 4, 0, 5 }));

	assert((scale(2, 1) * c == Circle{ 4, 0, 10 }));
	assert((scale(2, 2) * c == Circle{ 4, 0, 10 }));
	assert((scale(1, 2) * c == Circle{ 4, 0, 10 }));

	assert((scale(-1, 1) * c == Circle{ 4, 0, 5 }));

	assert((rotate(45) * c == Circle{ 0, 0, 5 }));*/

	AABB testA = { 1,2,  3,4 };

	assert((testA.min() == vec2{ -2, -2 }));
	assert((testA.max() == vec2{ 4,6 }));

	///////////////////////////////////////////////////////////////
	/////////////// Collisions

	assert(collisionDetection1D(0, 2, 1, 3).result() == true);
	assert(collisionDetection1D(0, 2, 1, 3).penetrationDepth == 1);

	assert(sweptDetection1D(0, 1, 5, 3, 4, 0).entryTime == .4f);

	AABB A = { 0,0, 2,4 };
	AABB B = { 2,2, 2,4 };

	assert(boxCollision(A, B).penetrationDepth == 2);
	assert((boxCollision(A, B).collisionNormal == vec2{ 1, 0 }));
	assert((boxCollision(B, A).collisionNormal == vec2{ -1, 0 }));

	AABB As = { 0,0, 1,1 };
	AABB Bs = { 0,10, 1,1 };

	assert(fequals(boxCollisionSwept(As, vec2{ 0,1 }, Bs, vec2{ 0, -1 }).entryTime, 4));
	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0, 1 }).entryTime, -6));
	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0, 1 }).exitTime, -4));


	AABB Bp = { 0,0,  4,4 };

	Plane P1 = { 0,0,0,1 };
	Plane P2 = { 0,-10,0,1 };
	Plane P3 = { 0,10,0,1 };

	Plane P4 = { vec2{6,6}, normal(vec2{-1,1}) };
	Plane P5 = { vec2{ 6,6 }, normal(vec2{ -1,-1 }) };

	assert(planeBoxCollision(P1, Bp).result());
	assert(!planeBoxCollision(P2, Bp).result());
	assert(planeBoxCollision(P3, Bp).result());
	assert(planeBoxCollision(P4, Bp).result());
	assert(!planeBoxCollision(P5, Bp).result());

	Plane P6 = { 10,0,-1,0 };

	assert(fequals(planeBoxCollisionSwept(P6, vec2{ 0,0 },Bp, vec2{ 1,0 }).entryTime,6.f));

	vec2 verts[] = { {0,1},{1,1},{1,0},{0,0} };
	vec2 verts2[] = { {-1,-1}, {-1,1},{0,0} };

	Hull myHull(verts, 4);
	Hull otherHull(verts2, 3);

	assert((myHull.normals[0] == vec2{ 0,1 }));
	assert((myHull.normals[1] == vec2{ 1,0 }));
	assert((myHull.normals[2] == vec2{ 0,-1 }));
	assert((myHull.normals[3] == vec2{ -1,0 }));

	assert((myHull.vertices[0] == vec2{ 0,1 }));
	assert((myHull.vertices[1] == vec2{ 1,1 }));
	assert((myHull.vertices[2] == vec2{ 1,0 }));
	assert((myHull.vertices[3] == vec2{ 0,0 }));

	Hull tHull = translate(1, 0) * myHull;

	assert((tHull.vertices[0] == vec2{ 1,1 }));
	assert((tHull.vertices[1] == vec2{ 2,1 }));
	assert((tHull.vertices[2] == vec2{ 2,0 }));
	assert((tHull.vertices[3] == vec2{ 1,0 }));

	assert(fequals(hullCollision(myHull, otherHull).penetrationDepth, 0));
	assert(fequals(hullCollision(otherHull, tHull).penetrationDepth, -1));

	///////////////////////////////////////////////////////////////
	/////////////// vec2 Collisions

	vec2 I = vec2{ -1,-1 };
	vec2 Ref = vec2{ 1,-1 };
	vec2 xaxis = vec2{ 1,0 };

	assert(project(I,xaxis) == -xaxis);

	vec2 ttt = reflect(I, xaxis);

	assert(reflect(I, xaxis) == Ref);

	getchar();
	return 0;
}