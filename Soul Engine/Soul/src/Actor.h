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
		int totalFrames;
		float frameDuration;
		float elapsedTime;
		int currentFrame;
	};

	struct SpriteSheet {
		std::string filePath;
		int numColumns;
		int numRows;
		float xScale;
		float yScale;
	};

	virtual void Start(){};
	virtual void OnUpdate(){};
	virtual void OnCollisionEnter(Actor& collision){};
	virtual void OnDestroyed(){};

	void AnimationUpdate(Animation& animation, float deltaTime);

	SpriteSheet sprite;
	Animation anim;
	Position position;
	

	bool pendingDelete = false;

	std::string objectType;

	

};

