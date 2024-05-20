#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Mocha
{
	class Light
	{
	
	public:
		Light();
		Light(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b, GLfloat ambientIntensity, GLfloat diffuseIntensity);
	
		~Light();
	
		void useLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation, GLuint diffuseIntensityLocation, GLuint directionLocation);
		void useLight();
	
	
	private:
	
		glm::vec3 m_colour;
		GLfloat m_ambientIntensity;
	
		glm::vec3 m_direction;
		GLfloat m_diffuseIntensity;
	};
}

