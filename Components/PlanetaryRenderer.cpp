#include "PlanetaryRenderer.h"
#include "sfwdraw.h"

PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size;
}

void PlanetaryRenderer::draw(Transform & planetTrans, const mat3 &camera)
{
	mat3 L = camera * planetTrans.getGlobalTransform();

	//float xRad = magnitude(L * vec3{ size,0,0 });
	//float yRad = magnitude(L * vec3{ 0,size,0 });

	vec3 pos = L[2];
	
	//float rad = xRad > yRad ? xRad : yRad;

	sfw::drawCircle(pos.x, pos.y, size, 12U, color);
}