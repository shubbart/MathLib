#include "AsteroidRender.h"
#include "sfwdraw.h"

AsteroidRender::AsteroidRender(unsigned a_color, float a_size)
{
	color = WHITE;
	size = 20;
}

void AsteroidRender::draw(Transform & astTrans, const mat3 & camera)
{
	mat3 L = camera * astTrans.getGlobalTransform();

	vec3 pos = L[2];

	sfw::drawCircle(pos.x, pos.y, size, 12U, color);
}
