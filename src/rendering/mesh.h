#pragma once

#include <glm/vec3.hpp>

#include "buffers/arrayBuffer.h"
#include "buffers/indexBuffer.h"

class Mesh
{
public:
	Mesh(ArrayBuffer* vao, IndexBuffer* ibo);

	static Mesh* Rectangle(float width, float height, glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));

	inline ArrayBuffer* getVAO() const { return vao; }
	inline IndexBuffer* getIBO() const { return ibo; }

	~Mesh();
private:
	ArrayBuffer* vao;
	IndexBuffer* ibo;
};