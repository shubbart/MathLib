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

	/*Transform player2Transform(1100, 600);
	player2Transform.scale = { 30,30 };

	Rigidbody player2Rigidbody;
	SpaceshipController player2Ctrl('J', 'L', 'I', 'K', 'M');
	SpaceshipLocomotion player2Loco;*/

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		if (playerTransform.m_position.x > SCREEN_WIDTH)
			playerTransform.m_position.x = 0.0f;
		else if (playerTransform.m_position.x < 0.0f)
			playerTransform.m_position.x = SCREEN_WIDTH;

		if (playerTransform.m_position.y > SCREEN_HEIGHT)
			playerTransform.m_position.y = 0.0f;
		else if (playerTransform.m_position.y < 0.0f)
			playerTransform.m_position.y = SCREEN_HEIGHT;

		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		playerTransform.debugDraw();
		playerRigidbody.debugDraw(playerTransform);

		/*if (player2Transform.m_position.x > SCREEN_WIDTH)
			player2Transform.m_position.x = 0.0f;
		else if (player2Transform.m_position.x < 0.0f)
			player2Transform.m_position.x = SCREEN_WIDTH;

		if (player2Transform.m_position.y > SCREEN_HEIGHT)
			player2Transform.m_position.y = 0.0f;
		else if (player2Transform.m_position.y < 0.0f)
			player2Transform.m_position.y = SCREEN_HEIGHT;

		player2Ctrl.update(player2Loco);
		player2Loco.update(player2Transform, player2Rigidbody);
		player2Rigidbody.integrate(player2Transform, deltaTime);

		player2Transform.debugDraw();
		player2Rigidbody.debugDraw(player2Transform);*/
	}

	sfw::termContext();
}