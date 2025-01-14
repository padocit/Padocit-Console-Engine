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

void Level::Update()
{
}

void Level::Render()
{
}
