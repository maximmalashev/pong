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
	void draw();

	inline Mesh* getMesh() const { return mesh; }
	inline Shader* getShader() const { return shader; }

	inline void setMesh(Mesh* mesh) { this->mesh = mesh; }
	inline void setShader(Shader* shader) { this->shader = shader; }

	~Entity();
private:
	Mesh* mesh;
	Shader* shader;
};