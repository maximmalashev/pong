#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "rendering/renderer.h"
#include "rendering/shader.h"

const float deg2rad = 3.14159265f / 180.0f;

int main()
{
	if (glfwInit() != GLFW_TRUE)
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(1080, 720, "Pong", nullptr, nullptr);
	if (!window)
	{
		std::cout << "Failed to create window." << std::endl;
		glfwTerminate();
		return -1;
	}

	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
	
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW is not OK." << std::endl;
		glfwTerminate();
		return -1;
	}

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, bufferWidth, bufferHeight);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0);

	/* Load resources */
	Shader* shader = Shader::load("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(bufferWidth / 2, bufferHeight / 2, -1.0f));
	model = glm::rotate(model, 0 * deg2rad, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(100.0f, 100.0f, 100.0f));

	glm::mat4 view = glm::identity<glm::mat4>();
	glm::mat4 projection = glm::ortho(0.0f, (float) bufferWidth, 0.0f, (float) bufferHeight, 0.1f, 100.0f);

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

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Renderer::draw(*shader, *vao, *ibo);

		glfwSwapBuffers(window);
	}
}