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

	Transform playerTransform(600, 600);
	Transform ST1(-2, -5);
	Transform ST2(-2, 5);
	Transform ST3(8, 3);




	playerTransform.m_scale = { 30, 30 };

	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;

	ST1.m_parent = &playerTransform;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;

	Rigidbody SRB1;
	SpaceshipController SC1;
	SC1.CTR_LEFT = 'J';
	SC1.CTR_RIGHT = 'L';
	SC1.CTR_UP = 'NULL';
	SC1.CTR_DOWN = 'NULL';
	SpaceshipLocomotion SL1;


	Rigidbody SRB2;
	SpaceshipController SC2;
	SC2.CTR_LEFT = 'I';
	SC2.CTR_RIGHT = 'K';
	SC2.CTR_UP = 'NULL';
	SC2.CTR_DOWN = 'NULL';
	SpaceshipLocomotion SL2;


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

		ST1.debugDraw();
		SC1.update(SL1);
		SL1.update(ST1, SRB1);
		SRB1.integrate(ST1, deltaTime);
		
		ST2.debugDraw();
		SC2.update(SL2);
		SL2.update(ST2, SRB2);
		SRB2.integrate(ST2, deltaTime);
		
		ST3.debugDraw();
	}

	sfw::termContext();
}