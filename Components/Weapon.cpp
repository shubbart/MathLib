#include "Weapon.h"
#include "sfwdraw.h"


Weapon::Weapon()
{
	timer = 0;

	vec2 hullVrts[] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
	collider = Collider(hullVrts, 4);

	transform.m_scale = vec2{ 2,2 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 5;

	isAlive = false;
	damage = 100;

}

void Weapon::update(float deltaTime, GameState & gs)
{
	timer -= deltaTime;
	isAlive = timer > 0;

	if (!isAlive) return;

	rigidbody.integrate(transform, deltaTime);

}

void Weapon::draw(const mat3 & camera)
{
	if (!isAlive) return;
	
	transform.debugDraw(camera);
	//collider.DebugDraw(camera, transform);
	render.draw(transform, camera);
	rigidbody.debugDraw(transform, camera);
	
}
