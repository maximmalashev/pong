#pragma once
#include <glm/mat4x4.hpp>

#include "entity.h"

const float deg2rad = 3.14159265f / 180.0f;

class OrthographicCamera : Entity
{
public:
	OrthographicCamera(float near, float far);

	glm::mat4 getProjectionMatrix(int bufferWidth, int bufferHeight);
	glm::mat4 getViewMatrix(int bufferWidth, int bufferHeight);

	void update() override;
	void draw() override;


	~OrthographicCamera();
private:
	float near, far;
};