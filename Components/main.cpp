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
	sfw::initContext(800, 600);
	Transform trans(400, 300);
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };

	/*sfw::initContext(1920, 1080);
	sfw::setBackgroundColor(BLACK);
	Transform trans;

	trans.position = vec2{ 960,540 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 30,15 };*/

	vec2 basis = { 40,0 };
	float ang_vec = 0;

	while (sfw::stepContext())
	{
		
		trans.debugDraw();

		ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dotProd(basis, normal(incident));

		sfw::drawLine(400, 300, 400 +basis.x, 300+basis.y, RED);
		sfw::drawLine(400, 300, 400 + incident.x, 300 + incident.y, GREEN);
		sfw::drawLine(400, 300, 400 + proj, 300 + proj, MAGENTA);

		//trans.facing -= sfw::getDeltaTime()*10;
		//trans.debugDraw();
		
		if (sfw::getKey(KEY_LEFT))
		{
			trans.position -= {10, 0};
			trans.facing += sfw::getDeltaTime() * 10;
		}
		if (sfw::getKey(KEY_RIGHT))
		{
			trans.position += {10, 0};
			trans.facing -= sfw::getDeltaTime() * 10;
		}

		if (sfw::getKey(KEY_DOWN))
		{
			trans.position -= {0, 10};
			trans.scale -= {sfw::getDeltaTime()*100, sfw::getDeltaTime() * 100};
		}
		if (sfw::getKey(KEY_UP))
		{
			trans.position += {0, 10};
			trans.scale += {sfw::getDeltaTime() * 100, sfw::getDeltaTime() * 100};
		}
	}

	sfw::termContext();
}