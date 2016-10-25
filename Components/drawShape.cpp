#include "drawShape.h"
#include "sfwdraw.h"

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
