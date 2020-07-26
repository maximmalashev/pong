#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "application.h"

#include "rendering/renderer.h"
#include "rendering/shader.h"
#include "rendering/window.h"

#include "game/orthographicCamera.h"

#include "pong/paddle.h"

int main()
{
	/* Create window & camera */
	Application::window = new Window(1080, 720, "Pong");
	Application::camera = new OrthographicCamera(-1.0f, 100.0f);

	/* Load shaders */
	Shader* shader = Shader::load("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

	/* Create mesh */
	Mesh* mesh = Mesh::Rectangle(1.0f, 1.0f);

	/* Create Paddles */
	Paddle* paddle1 = new Paddle();
	paddle1->setMesh(mesh);
	paddle1->setShader(shader);

	paddle1->transform.scale.x = 10.0f;
	paddle1->transform.scale.y = 70.0f;

	paddle1->transform.position.x = -500.0f;

	Paddle* paddle2 = new Paddle();
	paddle2->setMesh(mesh);
	paddle2->setShader(shader);

	paddle2->transform.scale.x = 10.0f;
	paddle2->transform.scale.y = 70.0f;

	paddle2->transform.position.x = 500.0f;
	
	/* Main loop */
	while (Application::window->running())
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		paddle1->update();
		paddle1->draw();

		paddle2->update();
		paddle2->draw();
		
		Application::window->swapBuffers();
	}
}