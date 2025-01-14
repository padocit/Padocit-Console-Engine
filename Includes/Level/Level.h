#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Container/Vector.h"

class Actor;
class ENGINE_API Level : public RTTI
{
	GENERATED_BODY(Level, RTTI)

public:
	Level();

	void AddActor();

	void Update();
	void Render();

protected:
	Vector<Actor*> actors;
};
