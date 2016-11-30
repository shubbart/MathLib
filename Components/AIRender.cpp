#include "AIRender.h"
#include "sfwdraw.h"
#include "AI.h"

AIRender::AIRender(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void AIRender::AIDraw(Transform & spaceshipTrans, const mat3 & camera)
{
	mat3 L = camera * spaceshipTrans.getGlobalTransform();

	vec3 pos = L[2];

	// Main body
	vec3 p1 = L *  vec3{ 0,2,1 };
	vec3 p2 = L *  vec3{ -1,-2,1 };
	vec3 p3 = L *  vec3{ 1,-2,1 };
	vec3 p4 = L *  vec3{ 0,-1,1 };

	sfw::drawLine(p1.x, p1.y, p2.x, p2.y, color);
	sfw::drawLine(p2.x, p2.y, p4.x, p4.y, color);
	sfw::drawLine(p4.x, p4.y, p3.x, p3.y, color);
	sfw::drawLine(p3.x, p3.y, p1.x, p1.y, color);

	// Pilot window
	vec3 p5 = L *  vec3{ 0,0.75f,1 };
	vec3 p6 = L *  vec3{ -0.35f,0,1 };
	vec3 p7 = L *  vec3{ 0.35f,0,1 };
	vec3 p8 = L *  vec3{ 0,-0.5f,1 };

	sfw::drawLine(p5.x, p5.y, p6.x, p6.y, CYAN);
	sfw::drawLine(p6.x, p6.y, p8.x, p8.y, CYAN);
	sfw::drawLine(p8.x, p8.y, p7.x, p7.y, CYAN);
	sfw::drawLine(p7.x, p7.y, p5.x, p5.y, CYAN);

	// Foward boost
	vec3 fBoost1 = L *  vec3{ 0,-3,1 };
	vec3 fBoost2 = L *  vec3{ -0.5f,-2,1 };
	vec3 fBoost3 = L *  vec3{ 0.5f,-2,1 };
	vec3 fBoost4 = L *  vec3{ 0,-1,1 };
	
	AI enemy;

	if (enemy.FORWARD == 1 && enemy.STOP != 1)
	{
		sfw::drawLine(fBoost1.x, fBoost1.y, fBoost2.x, fBoost2.y, RED);
		sfw::drawLine(fBoost2.x, fBoost2.y, fBoost4.x, fBoost4.y, RED);
		sfw::drawLine(fBoost4.x, fBoost4.y, fBoost3.x, fBoost3.y, RED);
		sfw::drawLine(fBoost3.x, fBoost3.y, fBoost1.x, fBoost1.y, RED);
	}
}
