#include "PreCompiledHeader.h"
#include "RenderableActor.h"
#include "Engine/Engine.h"

RenderableActor::RenderableActor(char image)
	: image(image)
{
}

void RenderableActor::Render()
{
	Super::Render();

	// 1. 콘솔 좌표 설정
	//Engine::Get()

	// 2. 그리기
}

void RenderableActor::SetPos(const Vec2& newPos)
{
	Super::SetPos(newPos);
}
