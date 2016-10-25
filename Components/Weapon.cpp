#include "Weapon.h"
#include "sfwdraw.h"

void Shoot(const Circle &c, unsigned color)
{

	Circle bullet = c;

	if (sfw::getKey(KEY_ENTER))
	{
		drawCircle(bullet, color);
	}
}
