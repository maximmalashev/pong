#pragma once

#include <vector>

#include "rendering/window.h"
#include "game/orthographicCamera.h"

#include "game/entity.h"

class Application
{
public:
	Application();
	~Application();

	static Window* window;
	static OrthographicCamera* camera;

	static std::vector<Entity*> entities;

	static int framerateCap;
	static int actualFramerate;

	static float deltaTime;

	inline static void addEntity(Entity* entity) { entities.push_back(entity); }
	static void deleteEntity(unsigned int id);
	static void handleKeyInput(GLFWwindow* window, int key, int code, int action, int mode);
	static void start();
};