#include "PreCompiledHeader.h"
#include "Engine.h"

// Singleton
Engine* Engine::instance = nullptr;

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
