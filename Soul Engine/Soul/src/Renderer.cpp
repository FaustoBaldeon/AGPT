#include "spch.h"

namespace Soul {


	float vertices[] = {
		// positions         // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	void Renderer::Init(SDL_Window* window)
	{
		if (window != nullptr)
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
			SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

			
			SDL_GLContext context = SDL_GL_CreateContext(window);

			if (context == nullptr) {
				std::cout << "[ERROR]: OpenGL context could not be created!" << std::endl;
				
				SDL_Quit();
				return;
			}
			else if (context != nullptr)
			{
				std::cout << "context created" << std::endl;
			}

			if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;

				SDL_Quit();
				return;
			}
			else
			{
				std::cout << "GLAD Initialized" << std::endl;
			}

			std::cout << "Renderer initialized!" << std::endl;

			InitRenderData();
		}

	}

	SDL_Texture* Renderer::LoadTexture(std::string filePath)
	{

		SDL_Texture* texture = nullptr;
		return texture;
	}

	void Renderer::InitRenderData() 
	{
		unsigned int VBO; 
		float vertices[] = { 
			// pos      // tex 
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};

		glGenVertexArrays(1, &this->quadVAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(this->quadVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		std::cout<<"data initialized"<<std::endl;
	}

	void Renderer::BackCol()
	{
		//std::cout<<"a"<<std::endl;
		glClear(GL_COLOR_BUFFER_BIT); 
		glClearColor(0.7f, 0.7f, 0.812f, 1.f);
		
	}

}