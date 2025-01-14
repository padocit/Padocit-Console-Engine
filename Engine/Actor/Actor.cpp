#include "PreCompiledHeader.h"
#include "Actor.h"

Actor::Actor()
	: pos(0, 0), isActive(true), isExpired(false)
{
}

void Actor::Update(float deltaTime)
{
}

void Actor::Render()
{
}

void Actor::SetPos(const Vec2& newPos)
{
	pos = newPos;
}

inline const Vec2& Actor::Pos() const
{
	return pos;
}
