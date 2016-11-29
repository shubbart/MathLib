#include "Asteroid.h"

Asteroid::Asteroid()
{
	vec2 hullVrts[] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
	collider = Collider(hullVrts, 4);
	render = AsteroidRender(WHITE);

	transform.m_scale = vec2{ 15,15 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 250;

	health = 100;

}

void Asteroid::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
	if (health <= 0)
		render = AsteroidRender(BLUE);
}

void Asteroid::draw(const mat3 & camera)
{

		transform.debugDraw(camera);
		render.draw(transform, camera);
		rigidbody.debugDraw(transform, camera);
	
}
