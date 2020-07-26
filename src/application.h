#pragma once

#include "rendering/window.h"
#include "game/orthographicCamera.h"

class Application
{
public:
	Application();
	~Application();

	static Window* window;
	static OrthographicCamera* camera;
};