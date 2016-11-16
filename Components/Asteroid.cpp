#include "Asteroid.h"
#include "AsteroidRender.h"

Asteroid::Asteroid()
{
	vec2 hullVrts[] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
	collider = Collider(hullVrts,4);

	transform.m_scale = vec2{ 15,15 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 250;

	health = 100;

}

void Asteroid::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 & camera)
{

		transform.debugDraw(camera);
		//collider.DebugDraw(camera, transform);
		render.draw(transform, camera);
		rigidbody.debugDraw(transform, camera);
	
}
