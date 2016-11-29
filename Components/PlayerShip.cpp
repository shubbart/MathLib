#include "PlayerShip.h"
#include "GameState.h"
#include <cstdio>


PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { { 0,2 },{ -1,-2 },{ 1,-2 } };
	collider = Collider(hullVrts, 3);
	transform.m_scale = vec2{ 5,5 };

}

void PlayerShip::update(float deltaTime, GameState & gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);

	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT) && !gs.weapon.isAlive)
	{
		// bring it to life
		gs.weapon.timer = 2.f;

		// set up it's position and stuff
		gs.weapon.transform.m_position = transform.m_position;
		gs.weapon.transform.m_facing = transform.m_facing;

		//reset velocity
		gs.weapon.rigidbody.velocity = vec2{ 0,0 };
		// get it moving
		gs.weapon.rigidbody.addImpulse(transform.getUp() * 3000.f);
	}

	if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
	{
		gs.tractor.isAlive = true; // reset the beam
		gs.tractor.oneFrame = false;
		// have it look where we are looking
		gs.tractor.transform.m_position = transform.m_position;
		gs.tractor.transform.m_facing = transform.m_facing;
	}


}

void PlayerShip::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	//collider.DebugDraw(camera, transform);
	render.color = 192192192;
	render.shipDraw(transform, camera);
}
