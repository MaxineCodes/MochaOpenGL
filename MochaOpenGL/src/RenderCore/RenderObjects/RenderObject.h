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
//  Overview:     blabla
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Mesh.h"
#include "Material.h"
#include "../Camera.h"
#include "../Lights/Light.h"

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
		void draw(Light* light);


		// Transformation
		void setTranslation(float x, float y, float z);
		void setRotation(float x, float y, float z);
		void setScale(float x, float y, float z);


	private:
		// Material:
		// Contains shader and textures
		Material* m_material;

		// Mesh:
		// Contains geometry
		//Mesh m_mesh;

		Mesh* m_mesh;

		Camera* m_camera_ptr;
		glm::mat4 m_projectionMatrix;

		// Model matrix to apply transformations to. Assigned as "empty" 1.0f matrix.
		// Gets passed to the vertex shader to apply transformations to the mesh.
		glm::mat4 m_modelMatrix = glm::mat4(1.0f);

		glm::vec3 m_translationVector, m_rotationVector, m_scaleVector;


		GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
		GLuint uniformAmbientIntensity = 0, uniformAmbientColour = 0;

		void applyTransforms();
	};
}

