#include "paddle.h"

#include "../application.h"

#include <iostream>

Paddle::Paddle(bool left) : left(left), topCollider(0), downCollider(0) { }

float Paddle::moveSpeed = 600.0f;

void Paddle::prepare()
{
	topCollider = Application::window->getBufferHeight() / 2 - transform.scale.y / 2;
	downCollider = -Application::window->getBufferHeight() / 2 + transform.scale.y / 2;
}

void Paddle::update() { }
void Paddle::frameUpdate() 
{
	int upKey = left ? GLFW_KEY_W : GLFW_KEY_UP;
	int downKey = left ? GLFW_KEY_S : GLFW_KEY_DOWN;

	if (Application::window->keys[upKey]) 
	{
		if (transform.position.y < topCollider)
			transform.position.y += moveSpeed * Application::deltaTime;
	}

	if (Application::window->keys[downKey])
	{
		if (transform.position.y > downCollider)
			transform.position.y -= moveSpeed * Application::deltaTime;
	}

}


Paddle::~Paddle() { }
