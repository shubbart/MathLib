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
#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"
#include "SpaceshipRenderer.h"
#include "Camera.h"
#include "Shapes.h"
#include "drawShape.h"
#include "Collision.h"

void main()
{
	float SCREEN_WIDTH = 1920;
	float SCREEN_HEIGHT = 1080;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfw::setBackgroundColor(BLACK);
	//float steps = 100;

	vec2 start = { 100,300 },
		end = { 450, 600 },
		mid1 = { -100, 550 },
		mid2 = { 980, 200 };

	Transform playerTransform(600, 600);

	playerTransform.m_scale = { 5, 5 };

	Rigidbody playerRigidbody;
	SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;
	SpaceshipRenderer playerRenderer(192192192, 30);
	

	//////////////////////////////////////////////////////////////////
	Transform sunTransform;
	sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = 0.5f;
	PlanetaryRenderer sunRenderer(YELLOW, 100);
	//////////////////////////////////////////////////////////////////
	Transform Planet1Transform;
	Planet1Transform.m_position = vec2{ -500, -175 };
	Planet1Transform.m_parent = &sunTransform;
	Rigidbody Planet1Rbody;
	PlanetaryMotor Planet1Motor;
	Planet1Motor.m_rotationSpeed = -3;
	PlanetaryRenderer Planet1Renderer(RED, 50);

	Transform P1MoonTransform;
	P1MoonTransform.m_position = vec2{ 75, 0 };
	P1MoonTransform.m_scale.x = 10;
	P1MoonTransform.m_parent = &Planet1Transform;
	PlanetaryRenderer P1MoonRenderer(WHITE, 5);

	Transform P1Moon2Transform;
	P1Moon2Transform.m_position = vec2{ -120, 75 };
	P1MoonTransform.m_scale = vec2{ 10, 10 };
	P1Moon2Transform.m_parent = &Planet1Transform;
	PlanetaryRenderer P1Moon2Renderer(WHITE, 8);
	//////////////////////////////////////////////////////////////////
	Transform Planet2Transform;
	Planet2Transform.m_position = vec2{ -300, 110 };
	Planet2Transform.m_parent = &sunTransform;
	Rigidbody Planet2Rbody;
	PlanetaryMotor Planet2Motor;
	Planet2Motor.m_rotationSpeed = -5;
	PlanetaryRenderer Planet2Renderer(GREEN, 25);

	Transform P2MoonTransform;
	P2MoonTransform.m_position = vec2{ 30, 30 };
	P2MoonTransform.m_parent = &Planet2Transform;
	PlanetaryRenderer P2MoonRenderer(WHITE, 10);
	//////////////////////////////////////////////////////////////////
	Transform Planet3Transform;
	Planet3Transform.m_position = vec2{ -850, -200 };
	Planet3Transform.m_parent = &sunTransform;
	Rigidbody Planet3Rbody;
	PlanetaryMotor Planet3Motor;
	Planet3Motor.m_rotationSpeed = 1;
	PlanetaryRenderer Planet3Renderer(BLUE, 30);

	Transform P3MoonTransform;
	P3MoonTransform.m_position = vec2{ 50, 50 };
	P3MoonTransform.m_parent = &Planet3Transform;
	PlanetaryRenderer P3MoonRenderer(WHITE, 12);

	Transform P3Moon2Transform;
	P3Moon2Transform.m_position = vec2{ -100, 75 };
	P3Moon2Transform.m_parent = &Planet3Transform;
	PlanetaryRenderer P3Moon2Renderer(WHITE, 7);
	//////////////////////////////////////////////////////////////////
	Transform Planet4Transform;
	Planet4Transform.m_position = vec2{ 150, -110 };
	Planet4Transform.m_parent = &sunTransform;
	Rigidbody Planet4Rbody;
	PlanetaryMotor Planet4Motor;
	Planet4Motor.m_rotationSpeed = -2;
	PlanetaryRenderer Planet4Renderer(MAGENTA, 10);

	Transform P4MoonTransform;
	P4MoonTransform.m_position = vec2{ 15, 15 };
	P4MoonTransform.m_parent = &Planet4Transform;
	PlanetaryRenderer P4MoonRenderer(WHITE, 3);
	//////////////////////////////////////////////////////////////////
	Transform Planet5Transform;
	Planet5Transform.m_position = vec2{ 1100, 410 };
	Planet5Transform.m_parent = &sunTransform;
	Rigidbody Planet5Rbody;
	PlanetaryMotor Planet5Motor;
	Planet5Motor.m_rotationSpeed = 2;
	PlanetaryRenderer Planet5Renderer(CYAN, 15);

	Transform P5MoonTransform;
	P5MoonTransform.m_position = vec2{ 50, 50 };
	P5MoonTransform.m_parent = &Planet5Transform;
	PlanetaryRenderer P5MoonRenderer(WHITE, 5);

	Transform cameraTransform;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// Wrap the player's position within the screen bounds
		/*if (playerTransform.m_position.x > SCREEN_WIDTH)
			playerTransform.m_position.x = 0.0f;
		else if (playerTransform.m_position.x < 0.0f)
			playerTransform.m_position.x = SCREEN_WIDTH;

		if (playerTransform.m_position.y > SCREEN_HEIGHT)
			playerTransform.m_position.y = 0.0f;
		else if (playerTransform.m_position.y < 0.0f)
			playerTransform.m_position.y = SCREEN_HEIGHT;*/


		// CAMERA
		cameraTransform.m_position
			= lerp(cameraTransform.m_position,
				playerTransform.getGlobalPosition(),
				sfw::getDeltaTime() * 10);

		// translation is the position of the camera ON THE SCREEN
		// the scale describes the zoom
		mat3 proj = translate(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		
		mat3 camera = proj * view;


		// Apply rigidbody forces
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);
	
		// Draw the player
		playerRenderer.shipDraw(playerTransform, camera);
		//playerRigidbody.debugDraw(playerTransform);
		playerTransform.debugDraw(camera);

	
		sunMotor.update(sunRbody);
		sunRbody.integrate(sunTransform, deltaTime);
		sunRenderer.draw(sunTransform, camera);

		//////////////////////////////////////////////////////////////////

		Planet1Motor.update(Planet1Rbody);
		Planet1Rbody.integrate(Planet1Transform, deltaTime);
		Planet1Renderer.draw(Planet1Transform, camera);
		
		P1MoonRenderer.draw(P1MoonTransform, camera);
		P1Moon2Renderer.draw(P1Moon2Transform, camera);

		//////////////////////////////////////////////////////////////////
		Planet2Motor.update(Planet2Rbody);
		Planet2Rbody.integrate(Planet2Transform, deltaTime);
		Planet2Renderer.draw(Planet2Transform, camera);
		
		P2MoonRenderer.draw(P2MoonTransform, camera);
		//////////////////////////////////////////////////////////////////
		Planet3Motor.update(Planet3Rbody);
		Planet3Rbody.integrate(Planet3Transform, deltaTime);
		Planet3Renderer.draw(Planet3Transform, camera);

		P3MoonRenderer.draw(P3MoonTransform, camera);
		P3MoonRenderer.draw(P3Moon2Transform, camera);
		//////////////////////////////////////////////////////////////////
		Planet4Motor.update(Planet4Rbody);
		Planet4Rbody.integrate(Planet4Transform, deltaTime);
		Planet4Renderer.draw(Planet4Transform, camera);

		P4MoonRenderer.draw(P4MoonTransform, camera);
		//////////////////////////////////////////////////////////////////
		Planet5Motor.update(Planet5Rbody);
		Planet5Rbody.integrate(Planet5Transform, deltaTime);
		Planet5Renderer.draw(Planet5Transform, camera);

		P5MoonRenderer.draw(P5MoonTransform, camera);
		//////////////////////////////////////////////////////////////////

	}

	sfw::termContext();
}