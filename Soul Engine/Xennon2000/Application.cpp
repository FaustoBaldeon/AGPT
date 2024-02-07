#include "spch.h"
#include "Level.h"
#include "Background.h"
#include "SpaceShip.h"
#include "Player.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Xenon2000", 640, 640);

	Level currentLevel;

	Background* background = new Background;

	SpaceShip* player = new SpaceShip;

	Player* testing = new Player;

	currentLevel.AddActor(background);
	currentLevel.AddActor(player);
	currentLevel.AddActor(testing);

	currentLevel.AddPawn(testing);

	engine.SetLevel(currentLevel);

	engine.Run();

	engine.Clean();

	delete player;
	delete background; 
	delete testing;

	return 0;
}
