#include "AI.h"
#include "sfwdraw.h"
#include "GameState.h"
#include <cstdio>
#include "flops.h"
#include <cmath>

AI::AI()
{
	vec2 hullVrts[] = { { 0,2 },{ -1,-2 },{ 1,-2 } };
	collider = Collider(hullVrts, 3);
	transform.m_scale = vec2{ 5,5 };
	isAlive = true;

}

void AI::update(SpaceshipLocomotion & loco, GameState & gs, float deltatime)
{
	locomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltatime);

	float hInput = 0.0f;
	hInput -= RIGHT;
	hInput += LEFT;

	float vInput = 0.0f;
	vInput += FORWARD;
	vInput -= STOP;

	float bInput = STOP;

	locomotion.doStop(bInput);
	locomotion.doTurn(hInput);
	locomotion.doThrust(vInput);

	// Shoot

	vec2 facing = normal(transform.getUp());
	vec2 dist = normal( transform.m_position - gs.player.transform.m_position);

	float view = acos(dotProd(facing, dist));
	view = rad2deg(view);

	float distX = abs(transform.m_position.x - gs.player.transform.m_position.x);
	float distY = abs(transform.m_position.y - gs.player.transform.m_position.y);

	if (view <= 180 && view >= 145 &&
		distX <= 180 && distY <= 180 &&
		!gs.aiWeapon.isAlive)
	{
		// bring it to life
		gs.aiWeapon.timer = 1.f;

		// set up it's position and stuff
		gs.aiWeapon.transform.m_position = transform.m_position;
		gs.aiWeapon.transform.m_facing = transform.m_facing;

		//reset velocity
		gs.aiWeapon.rigidbody.velocity = vec2{ 0,0 };
		// get it moving
		gs.aiWeapon.rigidbody.addImpulse(transform.getUp() * 3000.f);
	}

		if (health <= 0)
			isAlive = false;
}

void AI::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	render.color = RED;
	render.AIDraw(transform, camera);
}

void AI::locate(Transform & Player, Transform & AItrans)
{
	RIGHT = 0;
	LEFT = 0;
	FORWARD = 1;
	STOP = 0;
	vec2 FindVec{ AItrans.m_position.x - Player.m_position.x, AItrans.m_position.y - Player.m_position.y };

	float angleTurn = angleBetween(FindVec, AItrans.getDirection());
	angleTurn = rad2deg(angleTurn);
	if (angleTurn <= 90 && angleTurn > 0) LEFT = 1;
	if (angleTurn >= 90 && angleTurn < 180) RIGHT = 1;
	if (angleTurn < 80 && angleTurn > 100)
	{
		STOP = 1;
		FORWARD = 0;
	}
}
