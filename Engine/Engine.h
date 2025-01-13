#pragma once

struct KeyState
{
	bool isKeyDown = false;
	bool wasKeyDown = false;
};

class Engine
{
public:

	Engine();
	~Engine();

	void Run();

protected:

	void ProcessInput();
	void Update(float deltaTime);
	void Render();

protected:

	float targetFrameRate = 60.0f;   // 목표 fps
	float targetOneFrameTime = 0.0f; // 목표 프레임시간

	bool quit = false;
	
	KeyState keyStates[255] = { };
};