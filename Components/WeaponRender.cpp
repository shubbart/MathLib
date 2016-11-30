#include "WeaponRender.h"
#include "sfwdraw.h"

WeaponRender::WeaponRender(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void WeaponRender::draw(Transform & weaponTrans, const mat3 & camera)
{
	mat3 L = camera * weaponTrans.getGlobalTransform();

	vec3 pos = L[2];

	sfw::drawCircle(pos.x, pos.y, size, 12U, color);
	sfw::drawCircle(pos.x, pos.y, size - 1, 12U, color);
	sfw::drawCircle(pos.x, pos.y, size - 2, 12U, color);
	sfw::drawCircle(pos.x, pos.y, size - 3, 12U, color);
	sfw::drawCircle(pos.x, pos.y, size - 4, 12U, color);
}
