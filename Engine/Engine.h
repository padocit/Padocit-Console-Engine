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

	// ��ǥ fps
	float targetFrameRate = 60.0f;
	// ��ǥ �����ӽð�
	float targetOneFrameTime = 0.0f;

	bool quit;
	
	KeyState keyStates[255];
};