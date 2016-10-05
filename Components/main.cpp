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
	int SCREEN_WIDTH = 800;
	int SCREEN_HEIGHT = 800;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfw::setBackgroundColor(BLACK);
	//float steps = 100;

	vec2 start = { 100,300 },
		end = { 450, 600 },
		mid1 = { -100, 550 },
		mid2 = { 980, 200 };

	Transform playerTransform(400, 400);
	playerTransform.scale = { 5,5 };

	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;
	
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		if (playerTransform.position.x > SCREEN_WIDTH)
			playerTransform.position.x = 0.0f;
		else if (playerTransform.position.x < 0.0f)
			playerTransform.position.x = SCREEN_WIDTH;

		if (playerTransform.position.y > SCREEN_HEIGHT)
			playerTransform.position.y = 0.0f;
		else if (playerTransform.position.y < 0.0f)
			playerTransform.position.y = SCREEN_HEIGHT;

		playerCtrl.update(playerLoco);
		playerLoco.update(playerRigidbody, deltaTime);
		playerRigidbody.update(playerTransform, deltaTime);

		playerTransform.debugDraw();
		//w00t
		
	}

	sfw::termContext();
}