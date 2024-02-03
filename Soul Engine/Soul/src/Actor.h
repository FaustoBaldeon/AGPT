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

	virtual void Start(){};
	virtual void OnUpdate(){};
	virtual void OnCollisionEnter(Actor& collision){};
	virtual void OnDestroyed(){};

	bool pendingDelete = false;

	std::string objectType;

	

};

