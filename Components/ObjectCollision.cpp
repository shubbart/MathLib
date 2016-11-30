#include "ObjectCollision.h"
#include <cstdio>


void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0 && as.health > 0)
	{
		// Some sort of negative feedback for colliding
		player.health -= 300;
	}

}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void WeaponAsteroidCollision(Weapon &b, Asteroid &a)
{
	// make sure the bullet is active!
	if (!b.isAlive) return;

	// Use dynamic resolution, so the bullet bumps stuff away.
	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			a.transform, a.rigidbody, a.collider);

	
	if (result.penetrationDepth >= 0)
	{
		//Reset the timer on the bullet to 0. This allows us
		//to shoot it again (From player's update).
		a.health = a.health - b.damage;
		a.render.size *= .85f;
		a.rigidbody.mass *= .85f;
		b.timer = 0;
	}
}

void TractorAsteroidCollision(Tractor & tractor, Asteroid & asteroid, PlayerShip & player)
{
	// Make sure the tractor is active!
	if (!tractor.isAlive) return;

	// We don't use resolution-- the tractor is non-physical!
	// Just want to know if the asteroid is in the beam.
	CollisionData result =
		ColliderCollision(tractor.transform, tractor.collider,
						asteroid.transform, asteroid.collider);
	
	CollisionData stick =
		ColliderCollision(player.transform, player.collider,
			asteroid.transform, asteroid.collider);


	// if it is
	if (result.penetrationDepth >= 0 && asteroid.health <= 0)
	{
		// find the direction between
		vec2 dir = normal(tractor.transform.getGlobalPosition() -
			asteroid.transform.getGlobalPosition());
		// and add a force to pull the objet toward us.
		asteroid.rigidbody.addForce(dir * 10000);

		if (stick.penetrationDepth >= 0)
		{
			asteroid.rigidbody.velocity = vec2{ 0,0 };
			asteroid.rigidbody.force = vec2{ 0,0 };
			//asteroid.rigidbody.mass = 10;
			//asteroid.transform = player.transform;
			//asteroid.transform.m_position = player.transform.m_position + vec2{ 0, 10.0f };

		}

		if(sfw::getKey('F'))
			asteroid.rigidbody.addForce(dir * -55000);
	}
}

void PlayerAICollision(PlayerShip & player, AI & ai)
{
	CollisionData result =
		ColliderCollision(player.transform, player.collider,
			ai.transform, ai.collider);

	if (result.penetrationDepth >= 0)
	{
		player.health -= 300;
		ai.health -= 100;
	}
}

void AIAsteroidCollision(AI & ai, Asteroid & asteroid)
{
	CollisionData result =
		ColliderCollision(ai.transform, ai.collider,
			asteroid.transform, asteroid.collider);

	if (result.penetrationDepth >= 0 && asteroid.health <= 0)
	{
		ai.health -= 100;
	}
}

void WeaponAICollision(Weapon & w, AI & ai)
{
	if (!w.isAlive) return;

	CollisionData result =
		ColliderCollision(w.transform, w.collider,
			ai.transform, ai.collider);


	if (result.penetrationDepth >= 0)
	{
		ai.health = ai.health - w.damage;
		w.timer = 0;
	}
}

void AIWeaponCollision(PlayerShip & player, AIWeapon & aiW)
{
	if (!aiW.isAlive) return;

	CollisionData result =
		ColliderCollision(player.transform, player.collider,
			aiW.transform, aiW.collider);


	if (result.penetrationDepth >= 0)
	{
		player.health = player.health - aiW.damage;
		aiW.timer = 0;
		//player.render.color = WHITE;
		//player.render.color = 192192192;
	}
}
