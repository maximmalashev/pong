#include <GL/glew.h>

#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count) 
	: data(data), count(count), id(0)
{
	glGenBuffers(1, &id);

	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	unbind();
}

void IndexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &id);
}
