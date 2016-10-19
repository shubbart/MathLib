#include "SpaceshipRenderer.h"
#include "sfwdraw.h"

SpaceshipRenderer::SpaceshipRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void SpaceshipRenderer::shipDraw(Transform & spaceshipTrans, const mat3 &camera)
{
	mat3 L = camera * spaceshipTrans.getGlobalTransform();

	vec3 pos = L[2];

	vec3 p1 = L *  vec3{ 0,2,1 };
	vec3 p2 = L *  vec3{ -1,0,1 };
	vec3 p3 = L *  vec3{ 1,0,1 };
	vec3 p4 = L *  vec3{ 0,-1,1 };

	sfw::drawLine(p1.x, p1.y, p2.x, p2.y);
	sfw::drawLine(p2.x, p2.y, p4.x, p4.y);
	sfw::drawLine(p4.x, p4.y, p3.x, p3.y);
	sfw::drawLine(p3.x, p3.y, p1.x, p1.y);

}