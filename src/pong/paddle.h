#pragma once

#include "../game/entity.h"

class Paddle : public Entity
{
public:
	Paddle(bool left);

	void update() override;
	void frameUpdate() override;


	static float moveSpeed;

	~Paddle();
private:
	bool left;
};