#include "application.h"
#include <iostream>

Window* Application::window = nullptr;
OrthographicCamera* Application::camera = nullptr;
std::vector<Entity*> Application::entities;
int Application::framerateCap = 60;
int Application::actualFramerate = 0;

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

void Application::start()
{
	double lastTime = glfwGetTime();
	int framesPassedLastSecond = 0;

	double lastFramerateTime = glfwGetTime();

	while (window->running())
	{
		double currentTime = glfwGetTime();
		glfwPollEvents();

		/* Framerate counter */
		if (currentTime - lastFramerateTime >= 1.0)
		{
			actualFramerate = framesPassedLastSecond;
			framesPassedLastSecond = 0;
			lastFramerateTime = currentTime;
		
			window->AddToTitle(" | " + std::to_string(actualFramerate) + " fps");
		}

		for (const auto& entity : entities)
		{
			entity->update();
		}

		if (currentTime - lastTime >= (1.0 / (double) framerateCap))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			for (const auto& entity : entities)
			{
				entity->frameUpdate();
				entity->draw();
			}
			window->swapBuffers();

			lastTime = currentTime;
			framesPassedLastSecond++;
		} 
	}
}

Application::~Application() { }