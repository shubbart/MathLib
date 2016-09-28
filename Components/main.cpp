#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "sfwdraw.h"
#include "Transform.h"

void main()
{
	sfw::initContext();
	sfw::setBackgroundColor(BLACK);
	Transform trans;

	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };

	while (sfw::stepContext())
	{
		trans.facing += sfw::getDeltaTime();
		trans.debugDraw();
	}

	sfw::termContext();
}