#pragma once
#include <string>
#include <iostream>
#include <vector>

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
		int currentFrame = 1;
	};

	struct SpriteSheet {
		std::string filePath;
		int numColumns;
		int numRows;
		float xScale = 1.f;
		float yScale = 1.f;
		bool rotate = false;
	};

	virtual void Start(){};
	virtual void OnUpdate(){};
	virtual void OnCollisionEnter(Actor& collision){};
	virtual void OnDestroyed(){};
	virtual void GetDamage(float damage){};

	void AnimationUpdate(float deltaTime);

	void UpdateTime(float currentdTime, float currentTime);

	SpriteSheet sprite;
	Animation anim;
	Position position;
	

	bool pendingDelete = false;

	std::string objectType;
	float dTime = 0.f;
	float sTime = 0.f;

	virtual void SetInitialPosition(float xpos, float ypos);

	void Destroy();

	protected:
	void SetSpritesheetData(std::string filePath, int numColumns, int numRows, float scaleX, float scaleY);
	void SetPosition(float positionX, float positionY);
	void SetAnimationData(int totalFrames, float frameDuration);

};

