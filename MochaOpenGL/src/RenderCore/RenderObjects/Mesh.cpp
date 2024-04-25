#include "Mesh.h"
#include "../../Logging/Logger.h"

Mocha::Mesh::Mesh(GLfloat* vertices, unsigned int* indices, unsigned int verticesCount, unsigned int indicesCount)
{
	Mocha::Logger::Log("mesh constructor");

	m_VAO = 0;
	m_VBO = 0;
	m_IBO = 0;
	m_indexCount = indicesCount;

	constructMesh(vertices, indices, verticesCount, indicesCount);
}

Mocha::Mesh::Mesh()
{
	Mocha::Logger::Log("default mesh constructor");

	m_VAO = 0;
	m_VBO = 0;
	m_IBO = 0;
	m_indexCount = 0;
}

Mocha::Mesh::~Mesh()
{
	clearMesh();
}

void Mocha::Mesh::constructMesh(GLfloat* vertices, unsigned int* indices, unsigned int verticesCount, unsigned int indicesCount)
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indicesCount, indices, GL_STATIC_DRAW);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * verticesCount, vertices, GL_STATIC_DRAW);

	// XYZ vertices
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 5, 0);
	glEnableVertexAttribArray(0);

	// UV vertices
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]) * 5, (void*)(sizeof(vertices[0]) * 3));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Mocha::Mesh::drawMesh()
{
	// If no buffers, don't draw anything :)
	if (m_VAO == 0 || m_VBO == 0 || m_IBO == 0) return;


	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);

	glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Mocha::Mesh::clearMesh()
{
	// Delete all buffers
	if (m_IBO != 0)
	{
		glDeleteBuffers(1, &m_IBO);
		m_IBO = 0;
	}
	if (m_VBO != 0)
	{
		glDeleteBuffers(1, &m_VBO);
		m_VBO = 0;
	}
	if (m_IBO != 0)
	{
		glDeleteVertexArrays(1, &m_VAO);
		m_VAO = 0;
	}

	m_indexCount = 0;
}

Mocha::Mesh Mocha::GenerateDefaultMesh()
{
	// Generate a basic cube with shit UV's 

	unsigned int indices[] = {
		0,1,2,// front
		0,3,2,
		0,4,7,// left
		0,7,3,
		4,5,6,// back
		4,6,7,
		1,2,6,// right
		1,5,6,
		0,1,4,// top
		1,4,5,
		2,6,7,// bottom
		2,3,7
	};

	GLfloat vertices[] = {
		//	    X,     Y,     Z,       U,    v
				1.0f,  1.0f,  1.0f,    1.0f,  0.0f, // 0
				1.0f,  1.0f, -1.0f,    1.0f,  1.0f, // 1
				1.0f, -1.0f, -1.0f,    1.0f,  1.0f, // 2
				1.0f, -1.0f,  1.0f,    1.0f,  1.0f, // 3
			   -1.0f,  1.0f,  1.0f,    0.0f,  0.0f, // 4
			   -1.0f,  1.0f, -1.0f,    0.0f,  1.0f, // 5
			   -1.0f, -1.0f, -1.0f,    1.0f,  0.0f, // 6
			   -1.0f, -1.0f,  1.0f,    1.0f,  1.0f, // 7
	};

	return Mesh(vertices, indices, 40, 36);
}
