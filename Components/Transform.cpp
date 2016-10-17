#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
}

vec2 Transform::getUp() const
{
	return -perp(getDirection());
}

vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 & dir)
{
	m_facing = angle(dir);
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 T = translate(m_position.x, m_position.y);
	mat3 R = rotate(m_facing);

	return T * S * R;
}

void Transform::debugDraw(const mat3 &T) const
{

	mat3 L = T * getLocalTransform();

	vec3 pos = L[2];

	vec3 right = L * vec3{ 1, 0,   1 };
	vec3 up = L * vec3{ 0, 1,   1 };

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);

	//sfw::drawCircle(pos.x, pos.y, 30, 12, BLUE);


	sfw::drawCircle(pos.x, pos.y, 30, 12U, BLUE);
	sfw::drawCircle(pos.x, pos.y, 28, 12U, BLUE);
	sfw::drawCircle(pos.x, pos.y, 26, 12U, BLUE);
	sfw::drawCircle(pos.x, pos.y, 24, 12U, BLUE);
	sfw::drawCircle(pos.x, pos.y, 22, 12U, CYAN);
	sfw::drawCircle(pos.x, pos.y, 20, 12U, CYAN);
	sfw::drawCircle(pos.x, pos.y, 18, 12U, CYAN);
	sfw::drawCircle(pos.x, pos.y, 16, 12U, CYAN);
	sfw::drawCircle(pos.x, pos.y, 14, 12U, CYAN);
	sfw::drawCircle(pos.x, pos.y, 12, 12U, MAGENTA);
	sfw::drawCircle(pos.x, pos.y, 10, 12U, MAGENTA);
	sfw::drawCircle(pos.x, pos.y, 8, 12U, MAGENTA);
	sfw::drawCircle(pos.x, pos.y, 6, 12U, YELLOW);
	sfw::drawCircle(pos.x, pos.y, 4, 12U, YELLOW);
	sfw::drawCircle(pos.x, pos.y, 2, 12U, YELLOW);
}