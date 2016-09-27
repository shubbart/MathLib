#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"

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

	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,0 }) == 0);
	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,1 }) == 1);

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

	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 0,1 }),
		deg2rad(0)));
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

	getchar();
	return 0;
}