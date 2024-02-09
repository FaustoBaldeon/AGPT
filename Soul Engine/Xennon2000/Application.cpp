#include "spch.h"
#include "Level.h"
#include "Background.h"
#include "Player.h"
#include "LonerSpawner.h"
#include "RusherSpawner.h"
#include "DroneSpawner.h"

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

	LonerSpawner* lonerSpawner = new LonerSpawner; 
	lonerSpawner->SetInitialPosition(-1.1f,0.f);
	lonerSpawner->SetLevel(levelptr); 
	lonerSpawner->timeToSpawn = 5.f;   

	RusherSpawner* rushSpawn = new RusherSpawner;
	rushSpawn->SetInitialPosition(0.f,1.1f);
	rushSpawn->SetLevel(levelptr);
	rushSpawn->timeToSpawn = 7.f;

	DroneSpawner* droneSpawn = new DroneSpawner;
	droneSpawn->SetInitialPosition(0.f,1.1f);
	droneSpawn->SetLevel(levelptr);
	droneSpawn->timeToSpawn = 10.f;

	player->SetLevel(levelptr);

	currentLevel.AddActor(background);
	currentLevel.AddActor(background2); 
	currentLevel.AddActor(player);

	currentLevel.AddPawn(player);

	currentLevel.AddActor(lonerSpawner);
	currentLevel.AddActor(rushSpawn);
	currentLevel.AddActor(droneSpawn);

	engine.SetLevel(levelptr);

	engine.Run();

	engine.Clean();


	delete background; 
	delete background2; 
	delete player;
	delete lonerSpawner;
	delete rushSpawn;
	delete droneSpawn;


	return 0;
}
