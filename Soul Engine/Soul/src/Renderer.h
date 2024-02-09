#pragma once
#include "spch.h"
#include "Shader.h"
#include "glad/glad.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Level.h"


namespace Soul {
	
	class Renderer{
	public:
		~Renderer();

		void Init(SDL_Window* window);

		unsigned int LoadTexture(std::string filePath);

		void Draw(Level* currentLevel);

		void SetCurrentTextCoords(int currentFrame, int totalFrames, int numColumns, int numRows);

	private:
		Shader* shader;

		void InitRenderData();

		void UpdateModelMatrix(glm::vec2 position, glm::vec2 scale, bool rotate);

		struct Texture{
			unsigned int textureID;
			std::string imgPath;
		};

		int isImageLoaded(std::string filePath);

		std::vector<Texture>textList;

		glm::vec3 zAxisRot = glm::vec3(0.f, 0.f, 1.f);
		float angleRot = -90.f;

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		
		const char* vertexShaderSource = R"glsl(
		#version 330 core

		in vec3 position;
		in vec2 texCoord;

		uniform vec2 currentTexCoord;
		uniform vec2 spriteDimensions;
		
		out vec2 TexCoord;

		uniform mat4 model;

		void main()
		{
			TexCoord = (texCoord * spriteDimensions) + currentTexCoord;
			gl_Position = model * vec4(position, 1.0);

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

