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
		/*
		gravity = std::make_unique<b2Vec2>(0.0f, -10.0f);
		world = std::make_unique<b2World>(*gravity); 

		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(0.f,-10.f);
		b2Body* groundBody = world->CreateBody(&groundBodyDef);
		b2PolygonShape groundBox;
		groundBox.SetAsBox(50.f,10.f);
		groundBody->CreateFixture(&groundBox,0.f);

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(0.f,4.f);
		dynamicBody = world->CreateBody(&bodyDef);

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(1.f,1.f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;

		fixtureDef.density = 1.f;
		fixtureDef.friction = .3f;

		dynamicBody->CreateFixture(&fixtureDef);
		*/
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
			/*
			for (int32 i = 0; i < 60; ++i)
			{
				world->Step(timeStep, velocityIterations, positionIterations);
				b2Vec2 position = dynamicBody->GetPosition();
				float angle = dynamicBody->GetAngle();
				printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
			}*/

			HandleEvents();

			for (int i = 0; i < currentLevel->actorsLevel.size(); ++i)
			{
				if (currentLevel->actorsLevel[i]->pendingDelete == true)
				{
					currentLevel->actorsLevel[i]->OnDestroyed();
					currentLevel->actorsLevel.erase(currentLevel->actorsLevel.begin()+i);
				}
			}

			for (int i = 0; i < currentLevel->actorsLevel.size(); ++i)
			{
				Actor* currentActor = currentLevel->actorsLevel[i];
				currentActor->OnUpdate();
				currentActor->AnimationUpdate(deltaTime);
				currentActor->UpdateTime(deltaTime, frameTime);
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
					key = "a";
					UpdatePawnsInput(key);
					break;

				case SDLK_d:
					key = "d";
					UpdatePawnsInput(key);
					break;

				case SDLK_w:
					key = "w";
					UpdatePawnsInput(key);
					break;

				case SDLK_s:
					key = "s";
					UpdatePawnsInput(key);
					break;

				case SDLK_SPACE:
					key = "space";
					UpdatePawnsInput(key);
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

	void Engine::SetLevel(Level* level)
	{
		currentLevel = level;
	}

	void Engine::UpdatePawnsInput(std::string keyPressed)
	{
		for (int i = 0; i < currentLevel->pawnsLevel.size(); ++i)
		{
			currentLevel->pawnsLevel[i]->OnKeyPressed(keyPressed);
	}

}
}
