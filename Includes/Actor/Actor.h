#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Math/Vec2.h"

class ENGINE_API Actor : public RTTI
{
	GENERATED_BODY(Actor, RTTI)

public:
	Actor();

	void Update(float deltaTime);
	void Render();

protected:
	Vec2 pos;

	bool isActive;
};

