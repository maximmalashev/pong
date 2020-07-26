#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "rendering/renderer.h"
#include "rendering/shader.h"
#include "rendering/window.h"

#include "game/orthographicCamera.h"

int main()
{
	/* Create window */
	Window window(1080, 720, "Pong");

	/* Load shaders */
	Shader* shader = Shader::load("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

	/* Create camera */
	OrthographicCamera* camera = new OrthographicCamera(0.1f, 100.0f);

	/* Set up matrices */
	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f));
	model = glm::rotate(model, 0 * deg2rad, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(100.0f, 100.0f, 100.0f));

	shader->setMVP(model, camera->getViewMatrix(window.getBufferWidth(), window.getBufferHeight()), camera->getProjectionMatrix(window.getBufferWidth(), window.getBufferHeight()));

	/* Create mesh */
	Mesh* mesh = Mesh::Rectangle(2.0f, 2.0f);
	
	/* Main loop */
	while (window.running())
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Renderer::drawMesh(*shader, *mesh);

		window.swapBuffers();
	}
}