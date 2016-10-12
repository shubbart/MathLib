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

vec2 Transform::getDirection()
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

	vec3 right = pos + L * vec3{ 1,0,1 };
	vec3 up = pos + L * vec3{ 0,1,1 };

	sfw::drawCircle(pos.x, pos.y, 30, 12U, BLUE);
	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);


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

	//vec2 dirEnd = m_position + getDirection()* m_scale.x;
	//vec2 upEnd = m_position - perp(getDirection()) * m_scale.y;

	//sfw::drawLine(m_position.x, m_position.y, dirEnd.x, dirEnd.y, RED);
	//sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);
}