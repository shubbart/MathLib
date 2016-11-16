
#include "ObjectCollision.h"


void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		// Some sort of negative feedback for colliding
		player.health -= 50;
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
		a.render.size *= .75f;
		b.timer = 0;
	}
	
	if (a.health <= 0)
	{
		a.transform.m_position = vec2{ -5000, -5000 };
		a.transform.m_scale *= 0;
		a.isAlive = false;
	}
}