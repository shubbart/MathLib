#include <cassert>
#include <cstdio>
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "sfwdraw.h"
#include "Transform.h"
#include <cmath>
#include "RigidBody.h"
#include "SpaceshipLocomotion.h"
#include "main.h"
#include "SpaceshipController.h"

void main()
{
	int SCREEN_WIDTH = 1200;
	int SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfw::setBackgroundColor(BLACK);
	//float steps = 100;

	vec2 start = { 100,300 },
		end = { 450, 600 },
		mid1 = { -100, 550 },
		mid2 = { 980, 200 };

	Transform playerTransform(100, 600);
	playerTransform.m_scale = { 30,30 };

	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Wrap the player's position within the screen bounds
		if (playerTransform.m_position.x > SCREEN_WIDTH)
			playerTransform.m_position.x = 0.0f;
		else if (playerTransform.m_position.x < 0.0f)
			playerTransform.m_position.x = SCREEN_WIDTH;

		if (playerTransform.m_position.y > SCREEN_HEIGHT)
			playerTransform.m_position.y = 0.0f;
		else if (playerTransform.m_position.y < 0.0f)
			playerTransform.m_position.y = SCREEN_HEIGHT;

		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		// Draw the player
		playerTransform.debugDraw();
		playerRigidbody.debugDraw(playerTransform);
	}

	sfw::termContext();
}