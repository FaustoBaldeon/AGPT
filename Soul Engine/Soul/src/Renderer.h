#pragma once
#include "spch.h"
#include "Shader.h"
#include "glad/glad.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Soul {
	
	class Renderer{
	public:

		void Init(SDL_Window* window);

		unsigned int LoadTexture(std::string filePath);

		void BackCol();

		void SetCurrentTextCoords(int currentFrame, int totalFrames, int numColumns, int numRows);

		//void transformModelMatrix(glm::vec3 position, glm::vec3 rotationAxis, float angle);


	private:
		
		void InitRenderData();

		std::vector<unsigned int>textList;

		glm::mat4 projectionMatrix = glm::ortho(0.0f, 640.0f, 640.0f, 0.0f, -1.0f, 1.0f); //maybe initialize with window sizes

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		


		const char* vertexShaderSource = R"glsl(
		#version 330 core

		in vec3 position;
		in vec2 texCoord;
		
		out vec2 TexCoord;

		uniform mat4 model;
		uniform mat4 projection;

		void main()
		{
			TexCoord = texCoord;
			gl_Position = vec4(position, 1.0);

		}
		)glsl";

		const char* fragmentShaderSource = R"glsl(
		#version 330 core

		in vec2 TexCoord;

		out vec4 outColor;

		uniform sampler2D ourTexture;

		void main()
		{
			vec4 imageColor = texture(ourTexture, TexCoord);

			if(imageColor == vec4(1.0f,0.f,1.0f,1.0f))
			discard;

			outColor = imageColor;
		})glsl";
		
	};
}

