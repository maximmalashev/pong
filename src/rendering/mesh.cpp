#include "mesh.h"

Mesh::Mesh(ArrayBuffer* vao, IndexBuffer* ibo) : vao(vao), ibo(ibo) { }

Mesh* Mesh::Rectangle(float width, float height, glm::vec3 color)
{
	ArrayBuffer* vao = new ArrayBuffer();

	float vertices[] = {
		-width / 2, -height / 2, 0.0f, color.x, color.y, color.z,
		 width / 2, -height / 2, 0.0f, color.x, color.y, color.z,
		 width / 2,  height / 2, 0.0f, color.x, color.y, color.z,
		-width / 2,  height / 2, 0.0f, color.x, color.y, color.z
	};

	std::vector<int> vboLayout;
	vboLayout.push_back(3);
	vboLayout.push_back(3);

	VertexBuffer* vbo = new VertexBuffer(vertices, 24, vboLayout);
	vao->attachVertexBuffer(*vbo);

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	IndexBuffer* ibo = new IndexBuffer(indices, 6);

	return new Mesh(vao, ibo);
}

Mesh::~Mesh() { }
