#include "TestLevel.h"
#include "Actor/Player.h"

TestLevel::TestLevel()
{
	AddActor(new Player('A'));
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
}
