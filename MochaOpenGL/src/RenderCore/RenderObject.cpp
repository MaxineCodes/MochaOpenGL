#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "RenderObject.h"
#include "../Logging/Logger.h"

#include "Rendering.h"

#include <iostream>

Mocha::RenderObject::RenderObject(Material* mat, Mesh* mesh, glm::mat4 projectionMatrix, Camera* camera)
{
	m_material = mat;
	m_mesh = mesh;
	//m_mesh = GenerateDefaultMesh();

	m_camera_ptr = camera;
	m_projectionMatrix = projectionMatrix;

	//m_camera_ptr = &RenderGlobals::camera;
	//m_projectionMatrix = RenderGlobals::projection;

	m_modelMatrix = glm::mat4(1.0f);

}

Mocha::RenderObject::RenderObject()
{
	Mocha::Logger::Log("default obj constructor");
	m_mesh = nullptr;
	m_material = nullptr;

	m_modelMatrix = glm::mat4(1.0f);
}

Mocha::RenderObject::~RenderObject()
{

}

void Mocha::RenderObject::draw()
{
	// Set the material to be active for the next draw
	m_material->useMaterial();

	// Apply view and projection matrix from the material's shader
	uniformProjection = m_material->getShader()->getProjectionMatrixLocation();
	uniformView = m_material->getShader()->getViewMatrixLocation();
	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(m_projectionMatrix));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(m_camera_ptr->calculateViewMatrix()));

	// Apply transformations stored in the member transform vectors
	applyTransforms();

	// Draw mesh
	m_mesh->drawMesh();


}

void Mocha::RenderObject::setTranslation(float x, float y, float z)
{
	m_translationVector = glm::vec3(x, y, z);
}

void Mocha::RenderObject::setRotation(float x, float y, float z)
{
	m_rotationVector = glm::vec3(x, y, z);
	//m_modelMatrix = glm::rotate(m_modelMatrix, 1.0f, glm::vec3(x, y, z));
}

void Mocha::RenderObject::setScale(float x, float y, float z)
{
	m_scaleVector = glm::vec3(x, y, z);
}

void Mocha::RenderObject::applyTransforms()
{
	uniformModel = m_material->getShader()->getModelMatrixLocation();

	m_modelMatrix = glm::mat4(1.0f);
	m_modelMatrix = glm::translate(m_modelMatrix, m_translationVector);
	m_modelMatrix = glm::rotate(m_modelMatrix, 1.57f, m_rotationVector);
	m_modelMatrix = glm::scale(m_modelMatrix, m_scaleVector);

	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(m_modelMatrix));
}
