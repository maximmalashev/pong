#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include "../utils/fileUtils.h"

#include "shader.h"

Shader* Shader::load(const char* vertexPath, const char* fragmentPath)
{
	Shader* shader = new Shader();

	std::string vertex = readFileAsString(vertexPath);
	std::string fragment = readFileAsString(fragmentPath);

	shader->compile(vertex, fragment);

	return shader;
}

void Shader::use()
{
	glUseProgram(id);
}

void Shader::clear()
{
	if (id != 0)
	{
		glDeleteProgram(id);
		id = 0;
	}
}

void Shader::setUniform1f(std::string location, float value)
{
	use();
	int locationId = glGetUniformLocation(id, location.c_str());
	glUniform1f(locationId, value);
}

void Shader::setUniformMat4(std::string location, glm::mat4 value)
{
	use();
	int locationId = glGetUniformLocation(id, location.c_str());
	glUniformMatrix4fv(locationId, 1, GL_FALSE, glm::value_ptr(value));	
}

void Shader::compile(std::string vertexCode, std::string fragmentCode)
{
	id = glCreateProgram();

	if (!id)
	{
		std::cout << "Error creating shader program." << std::endl;
		return;
	}

	add(vertexCode.c_str(), GL_VERTEX_SHADER);
	add(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

	glLinkProgram(id);
	if (!checkProgramStatus(GL_LINK_STATUS)) { std::exit(-1); }

	glValidateProgram(id);
	if (!checkProgramStatus(GL_VALIDATE_STATUS)) { std::exit(-1); }
}

void Shader::add(const char* shaderCode, GLenum type)
{
	unsigned int shader = glCreateShader(type);

	const char* code[1];
	code[0] = shaderCode;

	int codeLength[1];
	codeLength[0] = strlen(shaderCode);

	glShaderSource(shader, 1, code, codeLength);
	glCompileShader(shader);

	glLinkProgram(shader);
	if (!checkShaderStatus(shader, GL_COMPILE_STATUS)) { std::exit(-1); }

	glAttachShader(id, shader);
}

bool Shader::checkProgramStatus(GLenum status)
{
	int result = 0;
	char eLog[1024] = { 0 };

	glGetProgramiv(id, status, &result);

	if (!result)
	{
		glGetProgramInfoLog(id, sizeof(eLog), nullptr, eLog);
		std::cout << "Error checking program status: " << eLog << std::endl;
		return false;
	}

	return true;
}

bool Shader::checkShaderStatus(unsigned int shader, GLenum status)
{
	int result = 0;
	char eLog[1024] = { 0 };

	glGetShaderiv(shader, status, &result);

	if (!result)
	{
		glGetShaderInfoLog(shader, sizeof(eLog), nullptr, eLog);
		std::cout << "Error checking shader status: " << eLog << std::endl;
		return false;
	}

	return true;
}

Shader::Shader() : id(0) { }
Shader::~Shader() { clear(); }