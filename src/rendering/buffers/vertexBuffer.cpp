#include <GL/glew.h>

#include "vertexBuffer.h"

VertexBuffer::VertexBuffer(float* data, unsigned int count, std::vector<int> layout) 
	: data(data), count(count), layout(layout)
{
	glGenBuffers(1, &id);

	bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, data, GL_STATIC_DRAW);
	unbind();
}

void VertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id);
}
