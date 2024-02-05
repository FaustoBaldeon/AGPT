#pragma once
#include <string>

class Actor
{
public:
	Actor();

	~Actor();

	struct Position {
		float x = 0.f;
		float y = 0.f;
	};

	struct Animation {
		int frameCount;
		float frameDuration;
		float elapsedTime;
		int currentFrame;
	};

	struct SpriteSheet {
		std::string filePath;
		int numColumns;
		int numRows;
	};

	virtual void Start(){};
	virtual void OnUpdate(){};
	virtual void OnCollisionEnter(Actor& collision){};
	virtual void OnDestroyed(){};

	void AnimationUpdate(Animation& animation, float deltaTime);
	

	bool pendingDelete = false;

	std::string objectType;

	

};

