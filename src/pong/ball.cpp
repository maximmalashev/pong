#include "ball.h"

#include "../application.h"
#include <iostream>
#include <cmath>

float Ball::minXVelocity = 250.0f;
float Ball::maxXVelocity = 350.0f;
float Ball::minYVelocity = 250.0f;
float Ball::maxYVelocity = 350.0f;

Ball::Ball() 
	: xVelocity(startXVelocity), yVelocity(0.0f), 
	  paddleLeft(nullptr), paddleRight(nullptr), 
	  colliderLeft(0), colliderRight(0), colliderTop(0), colliderBottom(0) { }

void Ball::prepare(Paddle* paddleLeft, Paddle* paddleRight)
{
	this->paddleLeft = paddleLeft;
	this->paddleRight = paddleRight;

	/* Set horizontal boundaries */
	colliderLeft = paddleLeft->transform.position.x + paddleLeft->transform.scale.x / 2 + transform.scale.x / 2;
	colliderRight = paddleRight->transform.position.x - paddleRight->transform.scale.x / 2 - transform.scale.x / 2;

	/* Set vertical boundaries */
	colliderTop = Application::window->getBufferHeight() / 2 - transform.scale.y / 2;
	colliderBottom = -Application::window->getBufferHeight() / 2 + transform.scale.y / 2;
}

void Ball::frameUpdate()
{
	/* Check paddle collision */
	if (!passed && (transform.position.x >= colliderRight || transform.position.x <= colliderLeft))
	{
		Paddle* currentPaddle = xDirection > 0 ? paddleRight : paddleLeft;
		float topPaddleCollider = currentPaddle->transform.position.y + currentPaddle->transform.scale.y / 2 + transform.scale.y / 2;
		float downPaddleCollider = currentPaddle->transform.position.y - currentPaddle->transform.scale.y / 2 - transform.scale.y / 2;

		if (transform.position.y <= topPaddleCollider && transform.position.y >= downPaddleCollider) paddleBounce();
		else if ((transform.position.x > 0) - (transform.position.x < 0) == xDirection) passed = true;
	}

	/* Check wall collision */
	if ((transform.position.y >= colliderTop && yDirection > 0) || (transform.position.y <= colliderBottom) && yDirection < 0) wallBounce();

	/* Change position */
	transform.position.x += xDirection * xVelocity * Application::deltaTime;
	transform.position.y += yDirection * yVelocity * Application::deltaTime;
}


void Ball::paddleBounce()
{
	xDirection = -xDirection;

	xVelocity = std::rand() % ((int) maxXVelocity - (int) minXVelocity) + minXVelocity;
	yVelocity = std::rand() % ((int) maxYVelocity - (int) minYVelocity) + minYVelocity;
}

void Ball::wallBounce()
{
	yDirection = -yDirection;

	float tmp = xVelocity;
	xVelocity = yVelocity;
	yVelocity = tmp;
}

void Ball::resetVelocities()
{
	xVelocity = startXVelocity;
	yVelocity = 0.0f;
}

void Ball::update() { }
Ball::~Ball() { }
