#include "GameState.h"
#include "ObjectCollision.h"
#include <cstdio>
#include <ctime>


void GameState::play()
{
	player.transform.m_position = vec2{ 750, 500 };
	player.transform.m_facing = 0;
	player.isAlive = true;

	ai.transform.m_position = vec2{ 800, 550 };
	ai.transform.m_facing = 0;
	ai.isAlive = true;
	
	//int asPos = rng.RandNum(-1000, 1000);
	//int asImpulse = rng.RandNum(-7000, 7000);

	for (int i = 0; i < asCount; ++i)
	{
		asPosX[i] = rng.RandNum(200, 800);
		asPosY[i] = rng.RandNum(200, 800);
		asImpulseX[i] = rng.RandNum(-7000, 7000);
		asImpulseY[i] = rng.RandNum(-7000, 7000);
		asteroid[i].transform.m_position = vec2{ asPosX[i],asPosY[i] };
		asteroid[i].rigidbody.addImpulse(vec2{ asImpulseX[i] ,asImpulseY[i] });
		asteroid[i].isAlive = true;
	}

	weapon.timer = 0;
	aiWeapon.timer = 0;
}

void GameState::update(float deltaTime)
{
		player.update(deltaTime, *this);
		camera.update(deltaTime, *this);
		weapon.update(deltaTime, *this);
		tractor.update(deltaTime, *this);
		ai.locate(player.transform, ai.transform);
		ai.locomotion.update(ai.transform, ai.rigidbody);
		ai.update(ai.locomotion, *this);
		ai.rigidbody.integrate(ai.transform, deltaTime);
		aiWeapon.update(deltaTime, *this);

		for (int i = 0; i < asCount; ++i)
			asteroid[i].update(deltaTime, *this);

		for (int i = 0; i < asCount; ++i)
			PlayerAsteroidCollision(player, asteroid[i]);

		for (int i = 0; i < asCount - 1; ++i)
			for (int j = i + 1; j < asCount; ++j)
				AsteroidCollision(asteroid[i], asteroid[j]);
		for (int i = 0; i < asCount; ++i)
			WeaponAsteroidCollision(weapon, asteroid[i]);

		for (int i = 0; i < asCount; ++i)
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
	ai.draw(cam);
	aiWeapon.draw(cam);

	for (int i = 0; i < asCount; ++i)
	{
		if (asteroid[i].isAlive = true)
		{
			asteroid[i].draw(cam);
		}
	}


}
