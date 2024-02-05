#include "Actor.h"

Actor::Actor()
{

}

Actor::~Actor()
{

}

void Actor::AnimationUpdate(Animation& animation, float deltaTime) {
	animation.elapsedTime += deltaTime;
	if (animation.elapsedTime >= animation.frameDuration)
	{
		animation.elapsedTime = 0.f;
		animation.currentFrame = (animation.currentFrame +1)%animation.frameCount;
	}
}
