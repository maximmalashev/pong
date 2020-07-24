#include <GL/glew.h>

#include "renderer.h"

void Renderer::draw(Shader &shader, ArrayBuffer &vao, IndexBuffer &ibo)
{
	shader.use();
	vao.bind();
	ibo.bind();

	glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, 0);

	vao.unbind();
	ibo.unbind();
}
