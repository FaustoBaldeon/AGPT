#include "spch.h"
#include "Level.h"
#include "Background.h"
#include "Player.h"
#include "LonerSpawner.h"
#include "RusherSpawner.h"
#include "Missiles.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Xenon2000", 640, 640);

	Level currentLevel;
	Level* levelptr = &currentLevel; 

	Background* background = new Background;
	Background* background2 = new Background;
	background2->SetInitialPosition(0.f,2.f);

	Player* player = new Player;

	LonerSpawner* spawner = new LonerSpawner; 
	spawner->SetInitialPosition(-1.1f,0.5f);
	spawner->SetLevel(levelptr); 
	spawner->timeToSpawn = 3.f;   

	RusherSpawner* rushSpawn = new RusherSpawner;
	rushSpawn->SetInitialPosition(0.f,1.1f);
	rushSpawn->SetLevel(levelptr);
	rushSpawn->timeToSpawn = 5.f;

	player->SetLevel(levelptr);

	currentLevel.AddActor(background);
	currentLevel.AddActor(background2); 
	currentLevel.AddActor(player);

	currentLevel.AddPawn(player);

	currentLevel.AddActor(spawner);
	currentLevel.AddActor(rushSpawn);

	engine.SetLevel(levelptr);

	engine.Run();

	engine.Clean();


	delete background; 
	delete background2; 
	delete player;
	delete spawner;
	delete rushSpawn;


	return 0;
}
