#pragma once
#include <string>
#include <iostream>

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
		int totalFrames = 1;
		float frameDuration = 0.1f;
		float elapsedTime = 0.f;
		int currentFrame = 1.f;
	};

	struct SpriteSheet {
		std::string filePath;
		int numColumns;
		int numRows;
		float xScale = 1.f;
		float yScale = 1.f;
	};

	virtual void Start(){};
	virtual void OnUpdate(){};
	virtual void OnCollisionEnter(Actor& collision){};
	virtual void OnDestroyed(){};

	void AnimationUpdate(float deltaTime);

	SpriteSheet sprite;
	Animation anim;
	Position position;
	

	bool pendingDelete = false;

	std::string objectType;

	protected:
	void SetSpritesheetData(std::string filePath, int numColumns, int numRows, float scaleX, float scaleY);
	void SetPosition(float positionX, float positionY);
	void SetAnimationData(int totalFrames, float frameDuration);
	

	


};

