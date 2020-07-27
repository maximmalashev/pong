#include "application.h"
#include <iostream>

Window* Application::window = nullptr;
OrthographicCamera* Application::camera = nullptr;

std::vector<Entity*> Application::entities;

int Application::framerateCap = 60;
int Application::actualFramerate = 0;

float Application::deltaTime = 1.0f;

Application::Application() { }

void Application::deleteEntity(unsigned int id)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getId() == id) 
		{
			entities.erase(entities.begin() + i);
			break;
		}
	}
}

void Application::handleKeyInput(GLFWwindow* window, int key, int code, int action, int mode)
{
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			Application::window->keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			Application::window->keys[key] = false;
		}
	}
}

void Application::start()
{
	double lastTime = glfwGetTime();
	int framesPassedLastSecond = 0;

	double lastFramerateTime = glfwGetTime();

	while (window->running())
	{
		double currentTime = glfwGetTime();

		/* Framerate counter */
		if (currentTime - lastFramerateTime >= 1.0)
		{
			actualFramerate = framesPassedLastSecond;
			framesPassedLastSecond = 0;
			lastFramerateTime = currentTime;
		
			window->addToTitle(" | " + std::to_string(actualFramerate) + " fps");
		}

		for (const auto& entity : entities)
		{
			entity->update();
		}

		if (currentTime - lastTime >= (1.0 / (double) framerateCap))
		{
			glfwPollEvents();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			for (const auto& entity : entities)
			{
				entity->frameUpdate();
				entity->draw();
			}

			deltaTime = currentTime - lastTime;

			window->swapBuffers();	

			lastTime = currentTime;
			framesPassedLastSecond++;
		}

	}
}

Application::~Application() { }