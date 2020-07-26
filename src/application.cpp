#include "application.h"

Window* Application::window = nullptr;
OrthographicCamera* Application::camera = nullptr;
std::vector<Entity*> Application::entities;

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
	while (window->running())
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (const auto& entity : entities)
		{
			entity->update();
			entity->draw();
		}

		window->swapBuffers();
	}
}

Application::~Application() { }