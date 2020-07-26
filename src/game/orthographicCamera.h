#pragma once
#include <glm/mat4x4.hpp>

#include "entity.h"

class OrthographicCamera : public Entity
{
public:
	OrthographicCamera(float near, float far);

	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix();

	void update() override;

	const float deg2rad = 3.14159265f / 180.0f;

	~OrthographicCamera();
private:
	float near, far;
};