#pragma once

#include "Core.h"

struct KeyState
{
	bool isKeyDown = false;
	bool wasKeyDown = false;
};

class ENGINE_API Engine
{
public:

	Engine();
	~Engine();

	void Run();

	// Singleton
	static Engine& Get();

protected:

	void ProcessInput();
	void Update(float deltaTime);
	void Render();

	void SetTargetFrameRate(float fps);

protected:
	// Singleton
	static Engine* instance;

	float targetFrameRate = 60.0f;   // ��ǥ fps
	float targetOneFrameTime = 0.0f; // ��ǥ �����ӽð�

	bool quit = false;
	
	KeyState keyStates[255] = { };
};