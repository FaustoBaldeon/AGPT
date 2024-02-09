#include "spch.h"
#include "Level.h"
#include "Background.h"
#include "Player.h"
#include "LonerSpawner.h"
#include "RusherSpawner.h"
#include "DroneSpawner.h"
#include "PowerUpsSpawner.h"
#include "MetalAsteroidsSpawner.h"
#include "StoneAsteroidsSpawner.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Xenon2000", 640, 640);

	Level currentLevel;
	Level* levelptr = &currentLevel; 

	Background* background = new Background;
	Background* background2 = new Background;
	background2->SetInitialPosition(2.f,0.f);

	Player* player = new Player;

	LonerSpawner* lonerSpawner = new LonerSpawner; 
	lonerSpawner->SetInitialPosition(1.1f,0.f);
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

	PowerUpsSpawner* powerupSpawn = new PowerUpsSpawner;
	powerupSpawn->SetInitialPosition(1.1f,0.f);
	powerupSpawn->SetLevel(levelptr);
	powerupSpawn->timeToSpawn = 5.f; 

	MetalAsteroidsSpawner* metalAsteroidsSpawn = new MetalAsteroidsSpawner;
	metalAsteroidsSpawn->SetInitialPosition(1.1f,0.f);
	metalAsteroidsSpawn->SetLevel(levelptr);
	metalAsteroidsSpawn->timeToSpawn= 4.f; 

	StoneAsteroidsSpawner* stoneAsteroidsSpawn = new StoneAsteroidsSpawner;
	stoneAsteroidsSpawn->SetInitialPosition(1.1f,0.f);
	stoneAsteroidsSpawn->SetLevel(levelptr);
	stoneAsteroidsSpawn->timeToSpawn = 6.f;

	player->SetLevel(levelptr);

	currentLevel.AddActor(background);
	currentLevel.AddActor(background2); 
	currentLevel.AddActor(player);

	currentLevel.AddPawn(player);

	currentLevel.AddActor(lonerSpawner);
	currentLevel.AddActor(rushSpawn);
	currentLevel.AddActor(droneSpawn);

	currentLevel.AddActor(powerupSpawn);
	currentLevel.AddActor(metalAsteroidsSpawn);
	currentLevel.AddActor(stoneAsteroidsSpawn);

	engine.SetLevel(levelptr);

	engine.Run();

	engine.Clean();

	
	for (auto actor : currentLevel.actorsLevel)
	{
		delete actor;
	}
	currentLevel.actorsLevel.clear();
	currentLevel.pawnsLevel.clear();

	return 0;
}
