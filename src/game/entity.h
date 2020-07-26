#pragma once

#include "../rendering/shader.h"
#include "../rendering/mesh.h"

#include <glm/vec3.hpp>


class Entity
{
public:
	struct Transform
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};

	Entity();

	Transform transform;

	virtual void update() = 0;
	virtual void draw() = 0;

	~Entity();
};