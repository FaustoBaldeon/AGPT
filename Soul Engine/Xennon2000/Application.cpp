#include "spch.h"
#include "Level.h"
#include "Background.h"
#include "Player.h"
#include "LonerSpawner.h"
#include "RusherSpawner.h"

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

	LonerSpawner* lonerSpawner1 = new LonerSpawner; 
	lonerSpawner1->SetInitialPosition(1.1f,0.f);
	lonerSpawner1->SetLevel(levelptr); 
	lonerSpawner1->timeToSpawn = 5.f;   

	LonerSpawner* lonerSpawner2 = new LonerSpawner;
	lonerSpawner2->SetInitialPosition(1.1f, 0.f);
	lonerSpawner2->SetLevel(levelptr);
	lonerSpawner2->timeToSpawn = 2.f;

	RusherSpawner* rushSpawn1 = new RusherSpawner;
	rushSpawn1->SetInitialPosition(0.f,1.1f);
	rushSpawn1->SetLevel(levelptr);
	rushSpawn1->timeToSpawn = 7.f;

	RusherSpawner* rushSpawn2 = new RusherSpawner;
	rushSpawn2->SetInitialPosition(0.f,1.1f);
	rushSpawn2->SetLevel(levelptr);
	rushSpawn2->timeToSpawn = 4.f;

	player->SetLevel(levelptr);

	currentLevel.AddActor(background);
	currentLevel.AddActor(background2); 

	currentLevel.AddActor(player);
	currentLevel.AddPawn(player);

	currentLevel.AddActor(lonerSpawner1);
	currentLevel.AddActor(rushSpawn1);
	currentLevel.AddActor(lonerSpawner2);
	currentLevel.AddActor(rushSpawn2);

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
