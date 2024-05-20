#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Light
{

public:
	Light();
	Light(GLfloat r, GLfloat g, GLfloat B, GLfloat ambientIntensity);

	~Light();

	void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation);



private:

	glm::vec3 m_colour;
	GLfloat m_ambientIntensity;

};

