#pragma once
#include "spch.h"
#include "Shader.h"
#include "glad/glad.h"
#include "stb_image.h"


namespace Soul {
	
	class Renderer{
	public:

		void Init(SDL_Window* window);

		unsigned int LoadTexture(std::string filePath);

		void BackCol();


	private:
		
		void InitRenderData();

		std::vector<unsigned int>textList;



		const char* vertexShaderSource = R"glsl(
		#version 330 core

		in vec3 position;
		in vec3 color;
		in vec2 texCoord;
		
		out vec3 Color;
		out vec2 TexCoord;

		uniform mat4 model;
		uniform mat4 projection;

		void main()
		{
			Color = color;
			TexCoord = texCoord;
			gl_Position = vec4(position, 1.0);

		}
		)glsl";

		const char* fragmentShaderSource = R"glsl(
		#version 330 core
		in vec3 Color;
		in vec2 TexCoord;

		out vec4 outColor;

		uniform sampler2D ourTexture;

		void main()
		{
			vec4 imageColor = texture(ourTexture, TexCoord);
			outColor = imageColor;
		})glsl";
		
	};
}

