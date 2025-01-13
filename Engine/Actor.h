#pragma once

class Actor
{
public:
	Actor();

	void Update(float deltaTime);
	void Render();

private:
	int posX;
	int posY;

	bool isActive;
};

