#include "spch.h"

namespace Soul 
{
	Engine* Engine::instance;

	void Engine::Initialize(const char* title, int width, int height)
	{
		//Initialize subsystems
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
		instance = this;
		std::cout << "Soul is starting...\n" << std::endl;
		
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "[ERROR]: SDL_Video not initialized..." << std::endl;
			return;
		}
		std::cout << "Subsystems initialized!" << std::endl;
		//Create window
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
		if (window == nullptr) {
			std::cout << "[ERROR]: Window could not be created..." << std::endl;

			SDL_Quit();
			return;
		}
		std::cout << "Window created!" << std::endl;
		//Initialize Renderer
		render.Init(window);
		//End init
		std::cout << "Soul has started! \n" << std::endl;
	}

	void Engine::Run() 
	{
		isRunning = true;

		while (isRunning) //Game Loop
		{
			currentTime = (float)SDL_GetTicks();
			deltaTime = (currentTime - previousTime) / 1000.f; 
			previousTime = currentTime;
			frameTime += deltaTime;
		
			HandleEvents();
			//std::cout << "Actors in level:"<<currentLevel.actorsLevel.size()<<std::endl;


			for (int i = 0; i < currentLevel.actorsLevel.size(); ++i)
			{
				if (currentLevel.actorsLevel[i]->pendingDelete == true)
				{
					currentLevel.actorsLevel[i]->OnDestroyed();
					currentLevel.actorsLevel.erase(currentLevel.actorsLevel.begin()+i);
				}
			}

			for (int i = 0; i < currentLevel.actorsLevel.size(); ++i)
			{
				currentLevel.actorsLevel[i]->OnUpdate();
				currentLevel.actorsLevel[i]->AnimationUpdate(deltaTime);
				//more update things
			}


			Render(); 

		}
	}

	void Engine::HandleEvents()
	{
		while (SDL_PollEvent(&event)) //Event Loop
		{
			if (event.type == SDL_QUIT)
				StopRunning();
			else if (event.type == SDL_KEYDOWN) 
			{
				switch (event.key.keysym.sym) {
				case SDLK_a:
					std::cout << "The A key was pressed!" << std::endl;
					break;

				case SDLK_d:
					std::cout << "The D key was pressed!" << std::endl;
					break;

				case SDLK_w:
					std::cout << "The W key was pressed!" << std::endl;
					break;

				case SDLK_s:
					std::cout << "The S key was pressed!" << std::endl;
					break;

				case SDLK_SPACE:
					std::cout << "The Space Bar was pressed!" << std::endl;
					break;

				default:
					break;
				}
			}
		}

		
	}

	void Engine::Render()
	{

		render.Draw(currentLevel);
		SDL_GL_SwapWindow(window); 
	}

	void Engine::StopRunning() 
	{ 
		isRunning = false;
		std::cout << "Soul is shutting down..." << std::endl;
		
	}

	void Engine::Clean() 
	{
		if (window != nullptr) {
			SDL_GL_DeleteContext(SDL_GL_GetCurrentContext());
			SDL_DestroyWindow(window); 
			window = nullptr; 
		};
	}

	void Engine::SetLevel(Level& level)
	{
		currentLevel = level;
	}

	Engine::Engine(){}

	Engine::~Engine(){}
}