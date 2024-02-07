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
	std::cout<<"actoradded"<<std::endl;
	actorsLevel.push_back(newActor);
	newActor->Start();
}

void Level::AddPawn(Pawn* newPawn)
{
	pawnsLevel.push_back(newPawn);
	newPawn->Start();
}

