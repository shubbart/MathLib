#include "GameState.h"
#include "ObjectCollision.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>


void GameState::play()
{
	text = sfw::loadTextureMap("./Resources/textmap.png", 16, 16);

	player.transform.m_position = vec2{ 750, 500 };
	player.transform.m_facing = 0;

	for (int i = 0; i < asCount; ++i)
	{
		asPosX[i] = rng.RandNum(-500, 1200);
		asPosY[i] = rng.RandNum(-500, 1200);
		asImpulseX[i] = rng.RandNum(-7000, 7000);
		asImpulseY[i] = rng.RandNum(-7000, 7000);
		asteroid[i].transform.m_position = vec2{ asPosX[i],asPosY[i] };
		asteroid[i].rigidbody.addImpulse(vec2{ asImpulseX[i] ,asImpulseY[i] });
		}

	for (int i = 0; i < aiCount; ++i)
	{
		aiPosX[i] = rng.RandNum(200, 1400);
		aiPosY[i] = rng.RandNum(100, 1400);
		ai[i].transform.m_position = vec2{ aiPosX[i],aiPosY[i] };
	}

	weapon.timer = 0;
	aiWeapon.timer = 0;
}

void GameState::update(float deltaTime)
{
	if (player.isAlive == true)
	{
		player.update(deltaTime, *this);
		weapon.update(deltaTime, *this);
		tractor.update(deltaTime, *this);
	}

		camera.update(deltaTime, *this);
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

		//AI
		for (int i = 0; i < aiCount; ++i)
			if(ai[i].isAlive == true)
			ai[i].update(ai[i].locomotion, *this, deltaTime);

		for (int i = 0; i < aiCount; ++i)
			if (ai[i].isAlive == true)
				ai[i].locate(player.transform, ai[i].transform);

		for (int i = 0; i < aiCount; ++i)
			if (ai[i].isAlive == true)
		ai[i].locomotion.update(ai[i].transform, ai[i].rigidbody);
		
		//AI Combat
		for (int i = 0; i < aiCount; ++i)
			if (ai[i].isAlive == true)
				if (player.isAlive == true)
			PlayerAICollision(player, ai[i]);

		for (int i = 0; i < asCount; ++i)
			for (int j = 0; j < aiCount; ++j)
				if (ai[j].isAlive == true)
			AIAsteroidCollision(ai[j], asteroid[i]);

		for (int i = 0; i < aiCount; ++i)
			if (ai[i].isAlive == true)
				if (player.isAlive == true)
			WeaponAICollision(weapon, ai[i]);

		for (int i = 0; i < aiCount; ++i)
			if (ai[i].isAlive == true)
				if (player.isAlive == true)
			AIWeaponCollision(player, aiWeapon);
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();

	if (player.isAlive == true)
	{
		player.draw(cam);
		weapon.draw(cam);
		tractor.draw(cam);
	}

	for (int i = 0; i < aiCount; ++i)
		if (ai[i].isAlive == true)
		{
			ai[i].draw(cam);
			if (player.isAlive == true)
			aiWeapon.draw(cam);
		}

	for (int i = 0; i < asCount; ++i)
		if (asteroid[i].isAlive = true)
			asteroid[i].draw(cam);
}
