#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "RenderObject.h"
#include "../Logging/Logger.h"

Mocha::RenderObject::RenderObject(Material* mat, Mesh* mesh)
{
	m_material = mat;
	m_mesh = mesh;
	//m_mesh = GenerateDefaultMesh();

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

void Mocha::RenderObject::draw(GLuint uniformModel)
{
	// Apply transformations stored in the model matrix
	//transform(uniformModel, m_modelMatrix);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(m_modelMatrix));

	// Draw mesh
	m_mesh->drawMesh();


}

void Mocha::RenderObject::transform(GLuint uniformModel, glm::mat4 modelTransformationMatrix)
{
	m_modelMatrix = modelTransformationMatrix;
	//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelTransformationMatrix));
}

void Mocha::RenderObject::translate(float x, float y, float z)
{
	m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(x, y, z));
}

void Mocha::RenderObject::rotate(float x, float y, float z)
{
	m_modelMatrix = glm::rotate(m_modelMatrix, 1.0f, glm::vec3(x, y, z));
}

void Mocha::RenderObject::scale(float x, float y, float z)
{
	m_modelMatrix = glm::scale(m_modelMatrix, glm::vec3(x, y, z));
}
