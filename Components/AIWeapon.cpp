#include "AIWeapon.h"
#include "sfwdraw.h"
#include "flops.h"
#include "GameState.h"


AIWeapon::AIWeapon()
{
	timer = 0;

	vec2 hullVrts[] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
	collider = Collider(hullVrts, 4);
	render.size = 4;
	render.color = YELLOW;
	transform.m_scale = vec2{ 2,2 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 5;

	isAlive = false;
	damage = 20;

}

void AIWeapon::update(float deltaTime, GameState & gs)
{
	timer -= deltaTime;
	isAlive = timer > 0;

	if (!isAlive) return;

	rigidbody.integrate(transform, deltaTime);
}

void AIWeapon::draw(const mat3 & camera)
{
	if (!isAlive) return;

	transform.debugDraw(camera);
	render.draw(transform, camera);
	rigidbody.debugDraw(transform, camera);

}