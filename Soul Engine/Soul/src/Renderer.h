#pragma once
#include "spch.h"
#include "Shader.h"
#include "glad/glad.h"


namespace Soul {
	
	class Renderer{
	public:

		void Init(SDL_Window* window);

		SDL_Texture* LoadTexture(std::string filePath);

		void BackCol();


	private:
		
		void InitRenderData();
		unsigned int quadVAO;
		
	};
}

