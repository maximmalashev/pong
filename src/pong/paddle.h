#pragma once

#include "../game/entity.h"

class Paddle : public Entity
{
public:
	Paddle();

	void update() override;

	~Paddle();
};