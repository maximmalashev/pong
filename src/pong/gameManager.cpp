#include "gameManager.h"

#include "../application.h"

#include <iostream>

GameManager::GameManager(Paddle* leftPaddle, Paddle* rightPaddle, Ball* ball) 
	: leftPaddle(leftPaddle), rightPaddle(rightPaddle), ball(ball) { }

void GameManager::update()
{
	int bufferWidth = Application::window->getBufferWidth();
	if (ball->transform.position.x < -bufferWidth / 2)
	{
		rightScore++;

		std::cout << "Left: " << leftScore;
		std::cout << ", Right: " << rightScore << std::endl;

		if (leftScore < winningScore && rightScore < winningScore) newRound();
		else endScreen();
	}

	if (ball->transform.position.x > bufferWidth / 2)
	{
		leftScore++;

		std::cout << "Left: " << leftScore;
		std::cout << ", Right: " << rightScore << std::endl;

		if (leftScore < winningScore && rightScore < winningScore) newRound();
		else endScreen();
	}
}

void GameManager::restart()
{
	leftScore = rightScore = 0;

	newRound();
}

void GameManager::newRound()
{
	ball->setPassed(false);
	ball->transform.position.x = 0;
	ball->transform.position.y = 0;

	ball->resetVelocities();

	leftPaddle->transform.position.y = 0;
	rightPaddle->transform.position.y = 0;
}

void GameManager::endScreen()
{
	std::cout << "Game ended!" << std::endl;
}

GameManager::~GameManager()
{
}
