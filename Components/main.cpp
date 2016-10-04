#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "sfwdraw.h"
#include "Transform.h"
#include <cmath>
#include "RigidBody.h"

void main()
{
	sfw::initContext(800, 800);
	//sfw::initContext(1920, 1080);
	sfw::setBackgroundColor(BLACK);
	float steps = 100;

	vec2 start = { 100,300 },
		end = { 450, 600 },
		mid1 = { -100, 550 },
		mid2 = { 980, 200 };

	Transform playerTransform(200, 200);
	Rigidbody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0,0 };
	
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		if (sfw::getKey('W')) playerRigidbody.velocity.y += 10.0f;
		if (sfw::getKey('S')) playerRigidbody.velocity.y -= 10.0f;
		if (sfw::getKey('D')) playerRigidbody.velocity.x += 10.0f;
		if (sfw::getKey('A')) playerRigidbody.velocity.x -= 10.0f;

		playerRigidbody.integrate(playerTransform, deltaTime);

		playerTransform.debugDraw();
		
	}

	sfw::termContext();
}