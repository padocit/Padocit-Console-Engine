#pragma once

#include "Level/Level.h"
#include "RTTI.h"

class TestLevel : public Level
{
	GENERATED_BODY(TestLevel, Level)

public:
	TestLevel();
	~TestLevel();
	
	virtual void Update(float deltaTime) override;

private:

};