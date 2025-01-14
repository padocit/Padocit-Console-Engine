#include "PreCompiledHeader.h"
#include "Engine.h"
#include "Math/Vec2.h"

// Singleton
Engine* Engine::instance = nullptr;
Engine& Engine::Get()
{
	return *instance;
}

Engine::Engine()
{
	SetTargetFrameRate(60.0f);

	instance = this;
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// 고해상도 카운터
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);

	int64_t lastFrameCounter = counter.QuadPart;
	int64_t currFrameCounter = 0;

	while (!quit)
	{
		// deltaTime 계산
		QueryPerformanceCounter(&counter);
		currFrameCounter = counter.QuadPart;
		float deltaTime = (currFrameCounter - lastFrameCounter) /
			static_cast<float>(frequency.QuadPart);

		if (deltaTime >= targetOneFrameTime)
		{
			ProcessInput();
			Update(deltaTime);
			Render();

			lastFrameCounter = currFrameCounter;
		}
	}
}


void Engine::ProcessInput()
{
}

void Engine::Update(float deltaTime)
{
	// debug - FPS log
	//std::cout << "deltaTime: " << deltaTime << ", FPS: " << 1.0f/deltaTime << std::endl;
}

void Engine::Render()
{
}

void Engine::SetTargetFrameRate(float fps)
{
	targetFrameRate = fps;
	targetOneFrameTime = 1.0f / targetFrameRate;
}

void Engine::SetCursorType(const CursorType& cursorType)
{
	// Cursor Info 설정
	CONSOLE_CURSOR_INFO info = { };
	
	switch (cursorType)
	{
	case CursorType::NoCursor:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case CursorType::SolidCursor:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case CursorType::NormalCursor:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	}

	// Cursor Info 적용
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Engine::SetCursorPos(const Vec2 cursorPos)
{
	SetCursorPos(cursorPos.x, cursorPos.y);
}

void Engine::SetCursorPos(const int x, const int y)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { static_cast<short>(x), static_cast<short>(y) };
	SetConsoleCursorPosition(handle, coord);
}
