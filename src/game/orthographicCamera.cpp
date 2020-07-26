#include "orthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

OrthographicCamera::OrthographicCamera(float near, float far) : near(near), far(far) { }

glm::mat4 OrthographicCamera::getProjectionMatrix(int bufferWidth, int bufferHeight)
{
	return glm::ortho(0.0f, (float) bufferWidth, 0.0f, (float) bufferHeight, near, far);
}

glm::mat4 OrthographicCamera::getViewMatrix(int bufferWidth, int bufferHeight)
{
	glm::mat4 view(1.0f);

	view = glm::translate(view, glm::vec3(bufferWidth / 2 - transform.position.x, bufferHeight / 2 - transform.position.y, 0.0f - transform.position.z));
	view = glm::rotate(view, transform.rotation.x * deg2rad, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, transform.rotation.y * deg2rad, glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, transform.rotation.z * deg2rad, glm::vec3(0.0f, 0.0f, 1.0f));
	view = glm::scale(view, transform.scale);

	return view;
}

void OrthographicCamera::update() { }

void OrthographicCamera::draw() { }

OrthographicCamera::~OrthographicCamera() { }
