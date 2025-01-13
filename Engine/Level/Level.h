#pragma once

class Actor;
class Level
{
public:
	Level();

	void AddActor();

	void Update();
	void Render();

private:
	// TODO: actors 동적 배열
};
