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

		void useShader();
		void clearShader();


	private:
		std::string readFile(const char* fileLocation);

		void compileShader(const char* vertexShaderSource, const char* fragmentShaderSource);
		void addShader(GLuint shaderProgramID, const char* shaderSource, GLenum shaderType);
		void setShaderUniforms();



	// --------------------
	// Uniforms definitions
	// --------------------

	public:
		// This shader's ID
		GLuint getShaderID() { return m_shaderID; }
		// Matrices
		GLuint getProjectionMatrixLocation() { return m_uniformProjectionMatrix; }
		GLuint getModelMatrixLocation() { return m_uniformModelMatrix; }
		GLuint getViewMatrixLocation() { return m_uniformViewMatrix; }
		// Camera
		GLuint getEyePositionLocation() { return m_uniformEyePosition; }
		//Lights
		GLuint getAmbientIntensityLocation() { return m_uniformAmbientIntensity; }
		GLuint getAmbientColourLocation() { return m_uniformAmbientColour; }
		GLuint getDiffuseIntensityLocation() { return m_uniformDiffuseIntensity; }
		GLuint getDirectionLocation() { return m_uniformDirection; }
		// Material
		GLuint getSpecularLocation() { return m_uniformSpecular; }
		GLuint getShininessLocation() { return m_uniformShininess; }

	private:
		GLuint

			// This shader's ID
			m_shaderID,
			// Matrices
			m_uniformProjectionMatrix,
			m_uniformModelMatrix,
			m_uniformViewMatrix,
			// Camera
			m_uniformEyePosition,
			//Lights
			m_uniformAmbientIntensity,
			m_uniformAmbientColour,
			m_uniformDiffuseIntensity,
			m_uniformDirection,
			// Material
			m_uniformSpecular,
			m_uniformShininess;
	};
}

