#pragma once

#include <string>
#include <glm/mat4x4.hpp>

class Shader
{
public:
	~Shader();

	static Shader* load(const char* vertexPath, const char* fragmentPath);

	void use();
	void clear();

	void setUniform1f(std::string location, float value);
	void setUniformMat4(std::string location, glm::mat4 value);

private:
	Shader();

	unsigned int id;

	void compile(std::string vertexCode, std::string fragmentCode);
	void add(const char* code, GLenum type);
	bool checkProgramStatus(GLenum status);
	bool checkShaderStatus(unsigned int shader, GLenum status);

};