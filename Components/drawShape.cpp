#include "drawShape.h"
#include "sfwdraw.h"
#include "mat3.h"


void drawCircle(const Circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, 12U, color);
}

void drawAABB(const AABB & B, unsigned color)
{
	vec2 m1 = B.min();
	vec2 m2 = B.max();

	sfw::drawLine(m1.x, m1.y, m2.x, m1.y, color);
	sfw::drawLine(m2.x, m1.y, m2.x, m2.y, color);
	sfw::drawLine(m1.x, m1.y, m1.x, m2.y, color);
	sfw::drawLine(m1.x, m2.y, m2.x, m2.y, color);
}

void drawPlane(const Plane & P, unsigned color)
{

	sfw::drawLine(P.pos.x, P.pos.y, P.pos.x + P.dir.x*10, P.pos.y + P.dir.y*10, color);

	vec2 left = perp(P.dir);
	vec2 right = -perp(P.dir);

	sfw::drawLine(P.pos.x, P.pos.y, P.pos.x + left.x * 80, P.pos.y + left.y * 80, color);
	sfw::drawLine(P.pos.x, P.pos.y, P.pos.x + right.x * 80, P.pos.y + right.y * 80, color);

}


