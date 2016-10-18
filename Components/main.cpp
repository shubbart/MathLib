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
	Transform ST1(-2, -8);
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
	//////////////////////////////////////////////////////////////////
	Transform sunTransform;
	sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = 1;
	PlanetaryRenderer sunRenderer(YELLOW, 100);
	//////////////////////////////////////////////////////////////////
	Transform arturoPlanetTransform;
	arturoPlanetTransform.m_position = vec2{ -300, -175 };
	arturoPlanetTransform.m_parent = &sunTransform;
	Rigidbody arturoPlanetRbody;
	PlanetaryMotor arturoPlanetMotor;
	arturoPlanetMotor.m_rotationSpeed = -3;
	PlanetaryRenderer arturoPlanetRenderer(RED, 50);

	Transform arturomoonTransform;
	arturomoonTransform.m_position = vec2{ 75, 0 };
	arturomoonTransform.m_scale.x = 10;
	arturomoonTransform.m_parent = &arturoPlanetTransform;
	PlanetaryRenderer arturoMoonRenderer(WHITE, 5);

	Transform arturomoon2Transform;
	arturomoon2Transform.m_position = vec2{ -120, 75 };
	arturomoonTransform.m_scale = vec2{ 10, 10 };
	arturomoon2Transform.m_parent = &arturoPlanetTransform;
	PlanetaryRenderer arturoMoon2Renderer(WHITE, 8);
	//////////////////////////////////////////////////////////////////
	Transform Planet2Transform;
	Planet2Transform.m_position = vec2{ -150, 110 };
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
	Planet3Transform.m_position = vec2{-400, 200 };
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
	P3Moon2Transform.m_position = vec2{-100, 75 };
	P3Moon2Transform.m_parent = &Planet3Transform;
	PlanetaryRenderer P3Moon2Renderer(WHITE, 7);
	//////////////////////////////////////////////////////////////////
	Transform Planet4Transform;
	Planet4Transform.m_position = vec2{ 175, -110 };
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
	Planet5Transform.m_position = vec2{ 300, 410 };
	Planet5Transform.m_parent = &sunTransform;
	Rigidbody Planet5Rbody;
	PlanetaryMotor Planet5Motor;
	Planet5Motor.m_rotationSpeed = 2;
	PlanetaryRenderer Planet5Renderer(CYAN, 15);

	Transform P5MoonTransform;
	P5MoonTransform.m_position = vec2{ 50, 50 };
	P5MoonTransform.m_parent = &Planet5Transform;
	PlanetaryRenderer P5MoonRenderer(WHITE, 5);


	

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

		sunMotor.update(sunRbody);
		sunRbody.integrate(sunTransform, deltaTime);
		sunRenderer.draw(sunTransform);
		//////////////////////////////////////////////////////////////////
		arturoPlanetMotor.update(arturoPlanetRbody);
		arturoPlanetRbody.integrate(arturoPlanetTransform, deltaTime);
		arturoPlanetRenderer.draw(arturoPlanetTransform);

		arturoMoonRenderer.draw(arturomoonTransform);
		arturoMoon2Renderer.draw(arturomoon2Transform);
		//////////////////////////////////////////////////////////////////
		Planet2Motor.update(Planet2Rbody);
		Planet2Rbody.integrate(Planet2Transform, deltaTime);
		Planet2Renderer.draw(Planet2Transform);
		
		P2MoonRenderer.draw(P2MoonTransform);
		//////////////////////////////////////////////////////////////////
		Planet3Motor.update(Planet3Rbody);
		Planet3Rbody.integrate(Planet3Transform, deltaTime);
		Planet3Renderer.draw(Planet3Transform);

		P3MoonRenderer.draw(P3MoonTransform);
		P3MoonRenderer.draw(P3Moon2Transform);
		//////////////////////////////////////////////////////////////////
		Planet4Motor.update(Planet4Rbody);
		Planet4Rbody.integrate(Planet4Transform, deltaTime);
		Planet4Renderer.draw(Planet4Transform);

		P4MoonRenderer.draw(P4MoonTransform);
		//////////////////////////////////////////////////////////////////
		Planet5Motor.update(Planet5Rbody);
		Planet5Rbody.integrate(Planet5Transform, deltaTime);
		Planet5Renderer.draw(Planet5Transform);

		P5MoonRenderer.draw(P5MoonTransform);
		//////////////////////////////////////////////////////////////////
	}

	sfw::termContext();
}