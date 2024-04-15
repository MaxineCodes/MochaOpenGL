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
	
		void drawMesh();
	
		void clearMesh();
	
		// Generate a basic cube with shit UV's 
		static Mesh generateDefaultMesh();
	
	
	private:
		GLuint m_VAO, m_VBO, m_IBO;
		GLsizei m_indexCount;
	};

	Mesh GenerateDefaultMesh();
}


