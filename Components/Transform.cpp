#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;

	facing = a;
}

vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y, 30, 12U, BLUE);

	/*sfw::drawCircle(position.x, position.y, 30, 12U, BLUE);
	sfw::drawCircle(position.x, position.y, 28, 12U, BLUE);
	sfw::drawCircle(position.x, position.y, 26, 12U, BLUE);
	sfw::drawCircle(position.x, position.y, 24, 12U, BLUE);
	sfw::drawCircle(position.x, position.y, 22, 12U, CYAN);
	sfw::drawCircle(position.x, position.y, 20, 12U, CYAN);
	sfw::drawCircle(position.x, position.y, 18, 12U, CYAN);
	sfw::drawCircle(position.x, position.y, 16, 12U, CYAN);
	sfw::drawCircle(position.x, position.y, 14, 12U, CYAN);
	sfw::drawCircle(position.x, position.y, 12, 12U, MAGENTA);
	sfw::drawCircle(position.x, position.y, 10, 12U, MAGENTA);
	sfw::drawCircle(position.x, position.y, 8, 12U, MAGENTA);
	sfw::drawCircle(position.x, position.y, 6, 12U, YELLOW);
	sfw::drawCircle(position.x, position.y, 4, 12U, YELLOW);
	sfw::drawCircle(position.x, position.y, 2, 12U, YELLOW);*/

	vec2 dirEnd = position + getDirection()* scale.x;
	vec2 upEnd = position - perp(getDirection()) * scale.y;

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);
	//sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);
}
