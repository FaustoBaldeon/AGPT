#include "Actor.h"

Actor::Actor()
{

}

Actor::~Actor()
{

}


void Actor::AnimationUpdate(float deltaTime) {
	anim.elapsedTime += deltaTime;
	if (anim.elapsedTime >= anim.frameDuration)
	{
		anim.elapsedTime = 0.f;
		anim.currentFrame = (anim.currentFrame +1)%anim.totalFrames;
	}
}

void Actor::SetAnimationData(int totalFrames, float frameDuration)
{
	anim.totalFrames = totalFrames;
	anim.frameDuration = frameDuration;
}

void Actor::SetPosition(float positionX, float positionY)
{
	position.x = positionX;
	position.y = positionY;
}

void Actor::SetSpritesheetData(std::string filePath, int numColumns, int numRows, float scaleX, float scaleY)
{
	sprite.filePath = filePath;
	sprite.numColumns = numColumns;
	sprite.numRows = numRows;
	sprite.xScale = scaleX;
	sprite.yScale = scaleY;
}
