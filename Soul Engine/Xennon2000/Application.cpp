#include "spch.h"
#include "Level.h"
#include "Background.h"
#include "SpaceShip.h"
#include "Player.h"
#include "Loner.h"
#include "Rusher.h"
#include "EnemyProjectiles.h"
#include "Drone.h"
#include "MetalAsteroids.h"
#include "SMetalAsteroid.h";
#include "MMetalAsteroid.h"

using namespace Soul;


int main(int argc, char** argv)
{
	Engine engine;

	engine.Initialize("Xenon2000", 640, 640);

	Level currentLevel;

	Background* background = new Background;
	Background* background2 = new Background;
	background2->SetInitialPosition(0.f,2.f);


	Loner* LonerTest = new Loner;

	Rusher* RusherTest = new Rusher;

	Drone* DroneTest = new Drone;

	MetalAsteroids* MAtest = new MetalAsteroids;

	SMetalAsteroid* SMATest = new SMetalAsteroid;

	MMetalAsteroid* MMATest = new MMetalAsteroid;

	currentLevel.AddActor(background);
	currentLevel.AddActor(background2); 


	currentLevel.AddActor(LonerTest);
	currentLevel.AddActor(RusherTest);
	currentLevel.AddActor(DroneTest);
	currentLevel.AddActor(MAtest);
	currentLevel.AddActor(SMATest);
	currentLevel.AddActor(MMATest);


	engine.SetLevel(currentLevel);

	engine.Run();

	engine.Clean();


	delete background; 
	delete background2; 
	delete LonerTest;
	delete RusherTest;
	delete DroneTest;
	delete MAtest;
	delete SMATest;
	delete MMATest;


	return 0;
}
