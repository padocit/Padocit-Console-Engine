#pragma once

#include "Actor/Actor.h"
#include "Core.h"

class ENGINE_API RenderableActor : public Actor
{
	GENERATED_BODY(RenderableActor, Actor)

public:
	RenderableActor(char image = ' ');
	virtual ~RenderableActor() = default;

	virtual void Render() override;
	virtual void SetPos(const Vec2& newPos);

private:
	char image = ' ';
};