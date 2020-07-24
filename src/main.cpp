#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "rendering/renderer.h"
#include "rendering/shader.h"

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
	shader->setUniform1f("testColor", 1.0f);

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