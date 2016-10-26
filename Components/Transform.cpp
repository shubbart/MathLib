#include "Transform.h"
#include "sfwdraw.h"
#include "drawShape.h"
#include "Shapes.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;

	m_parent = nullptr;
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

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}

vec2 Transform::getGlobalRight() const
{
	return getGlobalTransform()[0].xy;
}

vec2 Transform::getGlobalUp() const
{
	return getGlobalTransform()[1].xy;
}

float Transform::getGlobalAngle() const
{
	//atan2f(y,x)
	return angle(getGlobalRight());
}

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();
	else
	return m_parent->getGlobalTransform() * getLocalTransform();
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 T = translate(m_position.x, m_position.y);
	mat3 R = rotate(m_facing);

	return T * R * S;
}

mat3 Transform::camera()
{
	return mat3();
}

void Transform::debugDraw(const mat3 &T) const
{

	mat3 L = T * getGlobalTransform();

	/*vec3 pos = L[2];
	vec3 sgp = m_parent ? T * m_parent->getGlobalTransform()[2] : pos;

	vec3 right = L * vec3{ 1, 0,   1 };
	vec3 up = L * vec3{ 0, 1,   1 };

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	//sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
	//sfw::drawLine(sgp.x, sgp.y, pos.x, pos.y, 0x888888FF);

	sfw::drawCircle(pos.x, pos.y, 20, 12, WHITE);

	/*sfw::drawCircle(pos.x, pos.y, 30, 12U, BLUE);
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
	sfw::drawCircle(pos.x, pos.y, 2, 12U, YELLOW);*/

	drawCircle(L * Circle{ 0,0, 2 }, MAGENTA);
	drawAABB(L * AABB{ 0,0,1,2 }, 0x888888FF);
}