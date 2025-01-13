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

	__forceinline const Engine& Get() const { return *instance; }

protected:

	void ProcessInput();
	void Update(float deltaTime);
	void Render();

	void SetTargetFrameRate(float fps);

protected:
	// Singleton
	static Engine* instance;

	float targetFrameRate = 60.0f;   // 목표 fps
	float targetOneFrameTime = 0.0f; // 목표 프레임시간

	bool quit = false;
	
	KeyState keyStates[255] = { };
};