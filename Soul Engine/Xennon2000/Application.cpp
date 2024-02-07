#include "spch.h"
#include "Level.h"
#include "Background.h"
#include "SpaceShip.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Xenon2000", 640, 640);

	Level currentLevel;

	Background* background = new Background;

	SpaceShip* player = new SpaceShip;

	currentLevel.AddActor(background);
	currentLevel.AddActor(player);

	engine.SetLevel(currentLevel);

	engine.Run();

	engine.Clean();

	delete player;
	delete background; 

	return 0;
}
