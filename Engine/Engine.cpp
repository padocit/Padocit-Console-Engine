#include "Engine.h"

#include <Windows.h>
#include <iostream>

// TODO: ����

Engine::Engine()
{
	targetFrameRate = 60.0f;
	targetOneFrameTime = 1.0f / targetFrameRate;
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// ���ػ� ī����
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);

	LONGLONG lastFrameCounter = counter.QuadPart;
	LONGLONG currFrameCounter = 0;

	float deltaTime = 0.0f;

	while (!quit)
	{
		// deltaTime ���
		QueryPerformanceCounter(&counter);
		currFrameCounter = counter.QuadPart;
		deltaTime += (currFrameCounter - lastFrameCounter) /
			static_cast<float>(frequency.QuadPart);

		if (deltaTime >= targetOneFrameTime)
		{
			ProcessInput();
			Update(deltaTime);
			Render();

			deltaTime = 0.0f;
		}

		lastFrameCounter = currFrameCounter;
	}
}

void Engine::ProcessInput()
{
}

void Engine::Update(float deltaTime)
{
	// debug�� log
	std::cout << "deltaTime: " << deltaTime << ", FPS: " << 1.0f/deltaTime << std::endl;
}

void Engine::Render()
{
}
