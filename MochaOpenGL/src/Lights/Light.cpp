#include "Light.h"

Light::Light()
{
	m_colour = glm::vec3(1.0f, 0.0f, 1.0f);
	m_ambientIntensity = 1.0f;

}

Light::Light(GLfloat r, GLfloat g, GLfloat b, GLfloat ambientIntensity)
{
	m_colour = glm::vec3(r, g, b);
	m_ambientIntensity = ambientIntensity;
}

Light::~Light()
{

}

void Light::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation)
{
	glUniform3f(ambientColourLocation, m_colour.x, m_colour.y, m_colour.z);
	glUniform1f(ambientIntensityLocation, m_ambientIntensity);
}
