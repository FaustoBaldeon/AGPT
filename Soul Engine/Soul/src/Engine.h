#pragma once
#include "spch.h"
#include "Renderer.h"
#include "Level.h"
#include "Actor.h"

namespace Soul 
{
	class Engine {

	public:
		void Initialize(const char* title, int width, int height);

		void Run();

		void Clean();
		
		bool IsRunning() { return isRunning; }

		static Engine* getEngine() { return instance; }

		void SetLevel(Level* level);

		float deltaTime = 0;

		/*
		std::unique_ptr<b2Vec2> gravity;
		std::unique_ptr<b2World> world;
		b2Body* dynamicBody;
		float timeStep = 1.f/60.f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;*/
	
	private:
		static Engine* instance;
		void HandleEvents(); 
		void UpdatePawnsInput(std::string keyPressed);
		void Render(); 
		void StopRunning();
		float previousTime = 0;
		float currentTime = 0;
		float frameTime = 0;
		bool isRunning = false;
		SDL_Window* window = nullptr;
		SDL_Event event;
		Renderer render;
		Level* currentLevel; 
		std::string key = "";
	};

}