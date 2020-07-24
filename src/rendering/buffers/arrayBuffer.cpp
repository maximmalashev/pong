#include <GL/glew.h>

#include "arrayBuffer.h"

ArrayBuffer::ArrayBuffer()
{
	glGenVertexArrays(1, &id);
}

void ArrayBuffer::attachVertexBuffer(VertexBuffer &vbo)
{
	bind();
	vbo.bind();

	int stride = 0;

	for (unsigned int location = 0; location < vbo.getLayout().size(); location++)
		stride += vbo.getLayout()[location] * sizeof(float);

	int offset = 0;

	for (unsigned int location = 0; location < vbo.getLayout().size(); location++)
	{
		glVertexAttribPointer(location, vbo.getLayout()[location], GL_FLOAT, GL_FALSE, stride, (const void*) offset);
		glEnableVertexAttribArray(location);

		offset += vbo.getLayout()[location] * sizeof(float);
	}

	unbind();
}

void ArrayBuffer::bind()
{
	glBindVertexArray(id);
}

void ArrayBuffer::unbind()
{
	glBindVertexArray(0);
}

ArrayBuffer::~ArrayBuffer()
{
	glDeleteVertexArrays(1, &id);
}
