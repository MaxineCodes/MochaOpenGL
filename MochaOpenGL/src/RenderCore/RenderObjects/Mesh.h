#pragma once

#include <GL/glew.h>


namespace Mocha 
{
	class Mesh
	{
	public:
		Mesh(GLfloat* vertices, unsigned int* indices, unsigned int verticesCount, unsigned int indicesCount);
		Mesh();
		~Mesh();

		void constructMesh(GLfloat* vertices, unsigned int* indices, unsigned int verticesCount, unsigned int indicesCount);
	
		void drawMesh();
	
		void clearMesh();
	
	
	private:
		GLuint m_VAO, m_VBO, m_IBO;
		GLsizei m_indexCount;
	};

	Mesh GenerateDefaultMesh();
}


