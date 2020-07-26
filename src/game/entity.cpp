#include "entity.h"

Entity::Entity() 
{
	transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

Entity::~Entity() { }
