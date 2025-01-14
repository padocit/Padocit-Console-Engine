#include "PreCompiledHeader/PreCompiledHeader.h"
#include "Game/Game.h"
#include "Engine/Engine.h"
#include "Level/TestLevel.h"

#include <iostream>

int main()
{
	Game game;
	Engine::Get().LoadLevel(new TestLevel);
	game.Run();
	return 0;
}