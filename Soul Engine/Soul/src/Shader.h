#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include "glm/glm.hpp"
#include "glad/glad.h"

class Shader
{
private:
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const char* fragmentShaderSource, const char* vertexShaderSource);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

	// set vertex attrib pointers
	void VertexAttribPointer(const std::string& name, int size, GLenum type, bool normalized, size_t stride, const void* offset);
private:
	unsigned int CreateShader(const char* fragmentShaderSource, const char* vertexShaderSource);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);

};

