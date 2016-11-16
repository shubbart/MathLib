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

	sfw::drawCircle(pos.x +10, pos.y, size, 12U, RED);
	sfw::drawCircle(pos.x -10, pos.y, size, 12U, RED);
}
