#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "application.h"

#include "rendering/renderer.h"
#include "rendering/shader.h"
#include "rendering/window.h"

#include "game/orthographicCamera.h"

#include "pong/gameManager.h"
#include "pong/paddle.h"
#include "pong/ball.h"

int main()
{
	/* Create window & camera */
	Application::window = new Window(1080, 720, "Pong");
	Application::camera = new OrthographicCamera(-1.0f, 100.0f);

	/* Input set up */
	Application::window->setKeyInput(Application::handleKeyInput);

	/* Load shaders */
	Shader* shader = Shader::load("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

	/* Create mesh */
	Mesh* mesh = Mesh::Rectangle(1.0f, 1.0f);

	/* Create objects */
	Paddle* paddle1 = new Paddle(true);
	paddle1->setMesh(mesh);
	paddle1->setShader(shader);

	paddle1->transform.scale.x = 10.0f;
	paddle1->transform.scale.y = 100.0f;

	paddle1->transform.position.x = -500.0f;

	paddle1->prepare();

	Paddle* paddle2 = new Paddle(false);
	paddle2->setMesh(mesh);
	paddle2->setShader(shader);

	paddle2->transform.scale.x = 10.0f;
	paddle2->transform.scale.y = 100.0f;

	paddle2->transform.position.x = 500.0f;

	paddle2->prepare();

	Ball* ball = new Ball();
	ball->setMesh(mesh);
	ball->setShader(shader);

	ball->transform.scale.x = 15.0f;
	ball->transform.scale.y = 15.0f;

	ball->prepare(paddle1, paddle2);

	/* Game manager */
	Application::manager = new GameManager(paddle1, paddle2, ball);

	/* Add objects to the entity list */
	Application::addEntity(paddle1);
	Application::addEntity(paddle2);
	Application::addEntity(ball);

	/* Start the application */
	Application::start();
}