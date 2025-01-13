#pragma once

#include "Math/Vec2.h"

class Actor
{
public:
	Actor();

	void Update(float deltaTime);
	void Render();

private:
	Vec2 pos;

	bool isActive;
};

