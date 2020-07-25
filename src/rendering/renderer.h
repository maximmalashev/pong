#pragma once

#include "shader.h"
#include "mesh.h"
#include "buffers/indexBuffer.h"
#include "buffers/arrayBuffer.h"

class Renderer
{
public:
	static void draw(Shader& shader, ArrayBuffer& vao, IndexBuffer& ibo);
	static void drawMesh(Shader& shader, Mesh& mesh);
};