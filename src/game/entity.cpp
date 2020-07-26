#include "entity.h"

#include <glm/gtc/matrix_transform.hpp>

#include "../rendering/renderer.h"
#include "../application.h"

Entity::Entity() : mesh(nullptr), shader(nullptr)
{
	this->id = idCounter++;

	transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

unsigned int Entity::idCounter = 1;

void Entity::draw()
{
	glm::mat4 model(1.0f);
	model = glm::translate(model, transform.position);
	model = glm::rotate(model, transform.rotation.x * Application::camera->deg2rad, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, transform.rotation.y * Application::camera->deg2rad, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, transform.rotation.z * Application::camera->deg2rad, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, transform.scale);

	shader->setMVP(
		model,
		Application::camera->getViewMatrix(),
		Application::camera->getProjectionMatrix()
	);

	Renderer::drawMesh(*shader, *mesh);
}

Entity::~Entity() { }
