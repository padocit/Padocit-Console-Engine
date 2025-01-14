#pragma once

#include "Actor/RenderableActor.h"

class Player : public RenderableActor
{
	GENERATED_BODY(Player, RenderableActor)

public:
	Player(char image = 'P');

	virtual void Update(float deltaTime) override;

private:

};