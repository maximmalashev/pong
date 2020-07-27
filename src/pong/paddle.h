#pragma once

#include "../game/entity.h"

class Paddle : public Entity
{
public:
	Paddle(bool left);

	void update() override;
	void frameUpdate() override;

	void prepare();

	static float moveSpeed;
	
	float topCollider;
	float downCollider;

	~Paddle();
private:
	bool left;
};