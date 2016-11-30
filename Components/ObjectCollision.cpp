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
		player.health -= 100;
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
		asteroid.rigidbody.addForce(dir * 15000);

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

		printf("%f\n", stick.penetrationDepth);
	}
}