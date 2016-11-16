#include "NavRender.h"
#include "sfwdraw.h"
#include "Navigation.h"
#include "Asteroid.h"
#include "GameState.h"


NavRender::NavRender(unsigned a_color, float a_size)
{
	unsigned color = MAGENTA;
	
}

void NavRender::draw(Transform & navTrans, const mat3 & camera, const vec3 pointers[])
{

	mat3 L = camera * navTrans.getGlobalTransform();

	vec3 pos = L[2];
	for (int i = 0; i < 4; ++i)
	{
		sfw::drawLine(pos.x, pos.y, pointers[i].x, pointers[i].y, color);
	}
}
