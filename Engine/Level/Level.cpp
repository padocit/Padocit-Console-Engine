#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{

}

void Level::AddActor(Actor* newActor)
{
	actors.PushBack(newActor);
}

void Level::Update(float deltaTime)
{
	for (const auto& actor : actors)
	{
		actor->Update(deltaTime);
	}
}

void Level::Render()
{
	for (const auto& actor : actors)
	{
		actor->Render();
	}
}
