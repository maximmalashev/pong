#include "paddle.h"

#include "../application.h"

#include <iostream>

Paddle::Paddle(bool left) : left(left) { }

float Paddle::moveSpeed = 400.0f;

void Paddle::update() { }
void Paddle::frameUpdate() 
{
	int upKey = left ? GLFW_KEY_W : GLFW_KEY_UP;
	int downKey = left ? GLFW_KEY_S : GLFW_KEY_DOWN;

	if (Application::window->keys[upKey]) 
	{
		transform.position.y += moveSpeed * Application::deltaTime;
	}

	if (Application::window->keys[downKey])
	{
		transform.position.y -= moveSpeed * Application::deltaTime;
	}

}

Paddle::~Paddle() { }
