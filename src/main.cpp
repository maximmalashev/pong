#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "rendering/renderer.h"
#include "rendering/shader.h"
#include "rendering/window.h"

const float deg2rad = 3.14159265f / 180.0f;

int main()
{
	/* Create window */
	Window window(1080, 720, "Pong");

	/* Load resources */
	Shader* shader = Shader::load("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(window.getBufferWidth() / 2, window.getBufferHeight() / 2, -1.0f));
	model = glm::rotate(model, 0 * deg2rad, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(100.0f, 100.0f, 100.0f));

	glm::mat4 view = glm::identity<glm::mat4>();
	glm::mat4 projection = glm::ortho(0.0f, (float) window.getBufferWidth(), 0.0f, (float) window.getBufferHeight(), 0.1f, 100.0f);

	shader->setMVP(model, view, projection);

	ArrayBuffer* vao = new ArrayBuffer();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	std::vector<int> vboLayout;
	vboLayout.push_back(3);
	vboLayout.push_back(3);

	VertexBuffer* vbo = new VertexBuffer(vertices, 18, vboLayout);
	vao->attachVertexBuffer(*vbo);

	unsigned int indices[] = {
		0, 1, 2
	};

	IndexBuffer* ibo = new IndexBuffer(indices, 3);

	while (window.running())
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Renderer::draw(*shader, *vao, *ibo);

		window.swapBuffers();
	}
}