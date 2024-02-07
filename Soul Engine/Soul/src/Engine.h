#pragma once
#include "spch.h"
#include "Renderer.h"
#include "Level.h"
#include "Actor.h"

namespace Soul 
{
	class Engine {

	public:
		Engine();

		~Engine();

		void Initialize(const char* title, int width, int height);

		void Run();

		void Clean();
		
		bool IsRunning() { return isRunning; }

		static Engine* getEngine() { return instance; }

		//Level* getLevel(){return &currentLevel;}

		void SetLevel(Level& level);

		float deltaTime = 0;
	

	private:

		static Engine* instance;
		void HandleEvents(); 
		void Render(); 
		void StopRunning();
		float previousTime = 0;
		float currentTime = 0;
		float frameTime = 0;
		bool isRunning = false;
		SDL_Window* window = nullptr;
		SDL_Event event;
		Renderer render;
		Level currentLevel; 
	};

}