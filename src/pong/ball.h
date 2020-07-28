#pragma once

#include "../game/entity.h"
#include "paddle.h"

class Ball : public Entity
{
public:
	Ball();

	void prepare(Paddle* paddleLeft, Paddle* paddleRight);

	void update() override;
	void frameUpdate() override;

	inline void setPassed(bool value) { passed = value; }

	void resetVelocities();

	~Ball();
private:
	float startXVelocity = 200.0f;

	float xVelocity;
	float yVelocity;

	float colliderLeft;
	float colliderRight;
	float colliderTop;
	float colliderBottom;

	int xDirection = 1;
	int yDirection = 1;
	bool passed = false;

	Paddle *paddleLeft, *paddleRight;

	void paddleBounce();
	void wallBounce();

	static float maxXVelocity;
	static float minXVelocity;
	static float maxYVelocity;
	static float minYVelocity;
};