#include "PreCompiledHeader.h"
#include "RenderableActor.h"
#include "Engine/Engine.h"

RenderableActor::RenderableActor(char image)
	: Actor(), image(image)
{
}

void RenderableActor::Render()
{
	Super::Render();

	// 1. �ܼ� ��ǥ �̵�
	Engine::Get().SetCursorPos(pos);

	// 2. �׸���
	Log("%c", image);
}

void RenderableActor::SetPos(const Vec2& newPos)
{
	Super::SetPos(newPos);
}
