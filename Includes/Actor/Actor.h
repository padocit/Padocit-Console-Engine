#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Math/Vec2.h"

class ENGINE_API Actor : public RTTI
{
	GENERATED_BODY(Actor, RTTI)

public:
	Actor();

	void Update(float deltaTime);
	virtual void Render();

	// Getter/Setter
	virtual void SetPos(const Vec2& newPos);
	inline const Vec2& Pos() const;

protected:
	Vec2 pos;

	bool isActive;
	bool isExpired;
};

