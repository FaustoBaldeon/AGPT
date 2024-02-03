#include "spch.h"

namespace Soul {


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

	unsigned int Renderer::LoadTexture(std::string filePath)
	{

		int width, height, nrChannels;
		unsigned char* image_data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);

		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture); 

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		if (image_data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(image_data);

		textList.push_back(texture);

		return texture; //return texture ID
	}

	void Renderer::InitRenderData() 
	{
		
		float vertices[] = {
			// positions         // colors           // texture coords
			0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		   -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
		};
		unsigned int indices[] = {  
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
		};

		GLuint vbo; // vertex buffer object 
		glGenBuffers(1, &vbo); // Generate 1 buffer 

		GLuint vao; 
		glGenVertexArrays(1, &vao); 

		GLuint ebo; 
		glGenBuffers(1, &ebo); 

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo); 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo); 
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

		Shader shader(fragmentShaderSource,vertexShaderSource); 

		shader.VertexAttribPointer("position", 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),(void*)0);
		shader.VertexAttribPointer("color", 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
		shader.VertexAttribPointer("texCoord", 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));



		//HARCODED FOR TEST ----------------------------------------------------------------------
		unsigned int textText = LoadTexture("Assets/galaxy2.bmp");

		shader.Bind();
		glBindVertexArray(vao);
		shader.SetUniform1i("ourTexture", textText);


	}

	void Renderer::BackCol()
	{
		//std::cout<<"a"<<std::endl;
		glClear(GL_COLOR_BUFFER_BIT); 
		glClearColor(0.7f, 0.7f, 0.812f, 1.f);

		//glActiveTexture(GL_TEXTURE0); 

		glBindTexture(GL_TEXTURE_2D, textList[0]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
		
	}

}