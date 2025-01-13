#pragma once

#include "Core.h"
#include "Container/Vector.h"

class Actor;
class ENGINE_API Level
{
public:
	Level();

	void AddActor();

	void Update();
	void Render();

protected:
	Vector<Actor*> actors;
};
