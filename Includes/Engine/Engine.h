#pragma once

#include "Core.h"
#include "Math/Vec2.h"

struct KeyState
{
	bool isKeyDown = false;
	bool wasKeyDown = false;
};

enum class CursorType
{
	NoCursor,
	SolidCursor,
	NormalCursor,
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

	// Cursor
	void SetCursorType(const CursorType& cursorType);
	void SetCursorPos(const Vec2& cursorPos);
	void SetCursorPos(const int x, const int y);


protected:
	// Singleton
	static Engine* instance;

	float targetFrameRate = 60.0f;   // 목표 fps
	float targetOneFrameTime = 0.0f; // 목표 프레임시간

	bool quit = false;
	
	KeyState keyStates[255] = { };
};