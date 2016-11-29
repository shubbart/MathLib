#include "GameState.h"
#include "ObjectCollision.h"
#include <cstdio>


void GameState::play()
{
	player.transform.m_position = vec2{ 600, 600 };
	player.transform.m_facing = 0;
	player.isAlive = true;
	
	asteroid[0].transform.m_position = vec2{ 520,620 };
	asteroid[0].rigidbody.addImpulse(vec2{ 6200, 7500 });
	asteroid[0].rigidbody.addTorque(24);
	asteroid[0].isAlive = true;


	asteroid[1].transform.m_position = vec2{700,650 };
	asteroid[1].rigidbody.addImpulse(vec2{ -6500, -6000 });
	asteroid[1].rigidbody.addTorque(-24);
	asteroid[1].isAlive = true;

	asteroid[2].transform.m_position = vec2{ 800,500 };
	asteroid[2].rigidbody.addImpulse(vec2{ -6200, 5500 });
	asteroid[2].rigidbody.addTorque(-24);
	asteroid[2].isAlive = true;

	asteroid[3].transform.m_position = vec2{ 530,850 };
	asteroid[3].rigidbody.addImpulse(vec2{ 5500, -7000 });
	asteroid[3].rigidbody.addTorque(24);
	asteroid[3].isAlive = true;

	weapon.timer = 0;
}

void GameState::update(float deltaTime)
{
		player.update(deltaTime, *this);
		camera.update(deltaTime, *this);
		weapon.update(deltaTime, *this);
		tractor.update(deltaTime, *this);

		for (int i = 0; i < 4; ++i)
			asteroid[i].update(deltaTime, *this);

		for (int i = 0; i < 4; ++i)
			navigate.update(deltaTime, *this, asteroid);


		for (int i = 0; i < 4; ++i)
			PlayerAsteroidCollision(player, asteroid[i]);

		for (int i = 0; i < 4 - 1; ++i)
			for (int j = i + 1; j < 4; ++j)
				AsteroidCollision(asteroid[i], asteroid[j]);
		for (int i = 0; i < 4; ++i)
			WeaponAsteroidCollision(weapon, asteroid[i]);

		for (int i = 0; i < 4; ++i)
			TractorAsteroidCollision(tractor, asteroid[i], player);
		
		if (player.health <= 0)
		{
			!player.isAlive;
			printf("You have died!\n");
		}
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
	weapon.draw(cam);
	tractor.draw(cam);
		
	for (int i = 0; i < 4; ++i)
	{
		if (asteroid[i].isAlive = true)
		{
			asteroid[i].draw(cam);
			navigate.draw(cam, navigate.pointers);
		}
	}


}
