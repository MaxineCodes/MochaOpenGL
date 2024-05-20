#include "Light.h"
#include "../Rendering.h"

Mocha::Light::Light()
{
	m_colour = glm::vec3(1.0f, 1.0f, 1.0f); // set default constructed colour to white 
	m_ambientIntensity = 0.1f; // set ambient intensity to 0.1 so it's nice and dim

	m_direction = glm::vec3(0.0f, -1.0f, 0.0f);
	m_diffuseIntensity = 0.5f;
}

Mocha::Light::Light(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b, GLfloat ambientIntensity, GLfloat diffuseIntensity)
{
	m_colour = glm::vec3(r, g, b);
	m_ambientIntensity = ambientIntensity;

	m_direction = glm::vec3(x, y, z);
	m_diffuseIntensity = diffuseIntensity;
}

Mocha::Light::~Light()
{

}

void Mocha::Light::useLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation, GLuint diffuseIntensityLocation, GLuint directionLocation)
{
	glUniform3f(ambientColourLocation, m_colour.x, m_colour.y, m_colour.z);
	glUniform1f(ambientIntensityLocation, m_ambientIntensity);

	glUniform3f(directionLocation, m_direction.x, m_direction.y, m_direction.z);
	glUniform1f(diffuseIntensityLocation, m_diffuseIntensity);
}

void Mocha::Light::useLight()
{
	

	//glUniform3f(Rendering::Uniforms::uniformAmbientColour, m_colour.x, m_colour.y, m_colour.z);
	//glUniform1f(Rendering::Uniforms::uniformAmbientIntensity, m_ambientIntensity);
	//
	//glUniform3f(Rendering::Uniforms::uniformDirection, m_direction.x, m_direction.y, m_direction.z);
	//glUniform1f(diffuseIntensityLocation, m_diffuseIntensity);
}
