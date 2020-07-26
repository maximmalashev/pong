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

	inline static void addEntity(Entity* entity) { entities.push_back(entity); }
	static void deleteEntity(unsigned int id);
	static void start();
};