/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	RenderObject.h
// 
// 
//  Description:  Class for renderobject.
//			      Simply create a new one and draw it through the draw() function.
//				  A renderobject contains all that is necessary for an object, 
//                such as a mesh, material, transformations, etc.
// 
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Shaders\Mesh.h"
#include "Shaders\Material.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

namespace Mocha 
{
	class RenderObject
	{

	public:
		RenderObject(Material* mat, Mesh* mesh);
		RenderObject();
		~RenderObject();


		// Draws the renderobject
		void draw(GLuint uniformModel);


		// Transformation
		void transform(GLuint uniformModel, glm::mat4 modelTransformationMatrix);

		void translate(float x, float y, float z);
		void rotate(float x, float y, float z);
		void scale(float x, float y, float z);


	private:
		// Material:
		// Contains shader and textures
		Material* m_material;

		// Mesh:
		// Contains geometry
		//Mesh m_mesh;

		Mesh* m_mesh;

		// Model matrix to apply transformations to. Assigned as "empty" 1.0f matrix.
		// Gets passed to the vertex shader to apply transformations to the mesh.
		glm::mat4 m_modelMatrix;

	};
}

