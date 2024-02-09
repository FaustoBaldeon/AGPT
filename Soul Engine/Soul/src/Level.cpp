#include "Level.h"
#include <iostream>
#include <memory>

Level::Level()
{

}

Level::~Level()
{

}

void Level::AddActor(Actor* newActor)
{
	newActor->Start(); 
	actorsLevel.push_back(newActor);
}

void Level::AddPawn(Pawn* newPawn)
{
	pawnsLevel.push_back(newPawn);
	newPawn->Start();
}

