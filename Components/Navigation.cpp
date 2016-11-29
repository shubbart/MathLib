#include "Navigation.h"
#include "Asteroid.h"
#include "GameState.h"
#include "sfwdraw.h"
#include "NavRender.h"

Navigation::Navigation()
{
	transform.m_scale = vec2{ 1,1 };
}

void Navigation::update(float deltaTime, GameState &gs, const Asteroid asteroid[])
{
	for (int i = 0; i < 4; ++i)
	{
		count[i] = asteroid[i];
		pointers[i].x = asteroid[i].transform.m_position.x;
		pointers[i].y = asteroid[i].transform.m_position.y;
	}

}

void Navigation::draw(const mat3 & camera, vec3 pointers[])
{
	render.color = MAGENTA;
	render.draw(transform, camera, pointers);
}
