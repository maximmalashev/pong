#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

class Window
{
public:
	Window(int width, int height, std::string title);

	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }
	inline int getBufferWidth() const { return bufferWidth; }
	inline int getBufferHeight() const { return bufferHeight; }
	inline std::string getTitle() const { return title; }
	inline bool running() const { return !glfwWindowShouldClose(window); }
	inline void swapBuffers() { glfwSwapBuffers(window); }

	~Window();
private:
	GLFWwindow* window;

	int width, height;
	int bufferWidth, bufferHeight;
	std::string title;
};