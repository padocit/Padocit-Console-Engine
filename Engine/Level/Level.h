#pragma once

#include "Container/Vector.h"

class Actor;
class Level
{
public:
	Level();

	void AddActor();

	void Update();
	void Render();

private:
	Vector<Actor*> actors;
};
