#pragma once
#include "../pong/paddle.h"
#include "../pong/ball.h"

class GameManager
{
public:
	GameManager(Paddle* leftPaddle, Paddle* rightPaddle, Ball* ball);
	void update();
	void restart();
	~GameManager();
private:
	Paddle *leftPaddle, *rightPaddle;
	Ball* ball;

	int leftScore = 0;
	int rightScore = 0;

	int winningScore = 10;

	void newRound();
	void endScreen();
};