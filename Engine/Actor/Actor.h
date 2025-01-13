#pragma once

#include "Core.h"
#include "Math/Vec2.h"

class ENGINE_API Actor
{
public:
	Actor();

	void Update(float deltaTime);
	void Render();

private:
	Vec2 pos;

	bool isActive;
};

