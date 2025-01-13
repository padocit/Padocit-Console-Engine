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

	float targetFrameRate = 60.0f;   // ��ǥ fps
	float targetOneFrameTime = 0.0f; // ��ǥ �����ӽð�

	bool quit = false;
	
	KeyState keyStates[255] = { };
};