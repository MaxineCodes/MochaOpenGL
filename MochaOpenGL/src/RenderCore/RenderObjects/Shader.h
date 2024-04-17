#pragma once

#include <GL/glew.h>
#include <string>

namespace Mocha
{
	class Shader
	{
	public:
		Shader(const char* vertexShaderSourceLocation, const char* fragmentShaderSourceLocation);
		Shader();
		~Shader();

		void createFromString(const char* vertexShaderSource, const char* fragmentShaderSource);
		void createFromFiles(const char* vertexShaderSourceLocation, const char* fragmentShaderSourceLocation);

		GLuint getProjectionMatrixLocation() { return m_uniformProjectionMatrix; };
		GLuint getModelMatrixLocation() { return m_uniformModelMatrix; };
		GLuint getViewMatrixLocation() { return m_uniformViewMatrix; };

		void useShader();
		void clearShader();


	private:

		GLuint m_shaderID, m_uniformProjectionMatrix, m_uniformModelMatrix, m_uniformViewMatrix;

		std::string readFile(const char* fileLocation);

		void compileShader(const char* vertexShaderSource, const char* fragmentShaderSource);
		void addShader(GLuint shaderProgramID, const char* shaderSource, GLenum shaderType);
	};
}

