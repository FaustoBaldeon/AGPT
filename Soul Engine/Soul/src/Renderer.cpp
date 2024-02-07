#include "spch.h"

namespace Soul {

/*
	float vertices[] = {
		// positions         // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,  
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,  
	   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f   
	};

	unsigned int indices[] = { 
		0, 1, 3,   
		1, 2, 3    
	};*/

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

	unsigned int Renderer::LoadTexture(std::string filePath)
	{
		int alreadyLoaded = isImageLoaded(filePath);

		if (alreadyLoaded == -1)
		{
			GLuint textID;
			glGenTextures(1, &textID);
			glBindTexture(GL_TEXTURE_2D, textID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			stbi_set_flip_vertically_on_load(true);

			int width, height, nrChannels;
			unsigned char* image_data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);

			if (image_data)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
				glGenerateMipmap(GL_TEXTURE_2D);

				Texture texture;
				texture.imgPath = filePath;
				texture.textureID = textID;
				textList.push_back(texture); 
				return textID;
			}
			else
			{
				std::cout << "Failed to load texture" << std::endl;
			}
			stbi_image_free(image_data); 
		}
		else
		{
			return alreadyLoaded; 
		}

	}

	void Renderer::InitRenderData() 
	{
		
		float vertices[] = {
			// positions         // texture coords (remove later)
			0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   
			0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   
		   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   
		   -0.5f,  0.5f, 0.0f,   0.0f, 1.0f    
		};
		unsigned int indices[] = {  
		0, 1, 3,   
		1, 2, 3    
		};

		GLuint vbo; 
		glGenBuffers(1, &vbo); 

		GLuint vao; 
		glGenVertexArrays(1, &vao); 

		GLuint ebo; 
		glGenBuffers(1, &ebo); 

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo); 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo); 
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

		shader = new Shader(fragmentShaderSource, vertexShaderSource); 
		shader->Bind();

		shader->VertexAttribPointer("position", 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),(void*)0);

		//--------------- remove text coord and change to uniforms ------------------
		shader->VertexAttribPointer("texCoord", 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
		shader->SetUniformMat4f("model", modelMatrix);

		glBindVertexArray(vao); 
		unsigned int textText = LoadTexture("Assets/galaxy2.bmp");	
		shader->SetUniform1i("ourTexture", 0);


	}

	void Renderer::Draw(Level& currentLevel)
	{
		glClear(GL_COLOR_BUFFER_BIT); 
		glClearColor(0.7f, 0.7f, 0.812f, 1.f); 
		glActiveTexture(GL_TEXTURE0); 

		for (int i = 0; i < currentLevel.actorsLevel.size(); ++i)
		{
			int currentTexture = LoadTexture(currentLevel.actorsLevel[i].sprite.filePath);
			glBindTexture(GL_TEXTURE_2D, currentTexture);
			UpdateModelMatrix(glm::vec2(currentLevel.actorsLevel[i].position.x, currentLevel.actorsLevel[i].position.y), 
							glm::vec2(currentLevel.actorsLevel[i].sprite.xScale, currentLevel.actorsLevel[i].sprite.yScale));
			SetCurrentTextCoords(currentLevel.actorsLevel[i].anim.currentFrame, currentLevel.actorsLevel[i].anim.totalFrames,
				currentLevel.actorsLevel[i].sprite.numColumns, currentLevel.actorsLevel[i].sprite.numRows);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		}

	}

	int Renderer::isImageLoaded(std::string filePath)
	{
		for (unsigned int i = 0; i < textList.size(); ++i)
		{
			if (filePath.compare(textList[i].imgPath) == 0)
				return textList[i].textureID;
		}
		return -1;
	}

	void Renderer::UpdateModelMatrix(glm::vec2 position, glm::vec2 scale)
	{
		modelMatrix = glm::mat4(1.f); 
		modelMatrix = glm::translate(modelMatrix, glm::vec3(position, 0.f)); 
		modelMatrix = glm::scale(modelMatrix, glm::vec3(scale, 1.0f)); 
		shader->SetUniformMat4f("model", modelMatrix); 
	}

	void Renderer::SetCurrentTextCoords(int currentFrame, int totalFrames, int numColumns, int numRows)
	{
		float frameWidth = 1.f/numColumns;
		float frameHeight = 1.f/numRows;

		int row = currentFrame/numColumns;
		int col = currentFrame%numColumns;

		float currrentXTextCoord = col*frameWidth;
		float nextXTextCoord = (col+1)*frameWidth;

		float currentYTextCoord = 1.f- row * frameHeight;
		float nextYTextCoord = 1.f - (row+1)*frameHeight;

		//UNIFORMS SETUP

	}

}