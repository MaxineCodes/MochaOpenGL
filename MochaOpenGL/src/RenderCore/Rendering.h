#pragma once

#include "..\Logging\Logger.h"

#include "RenderObject.h"
#include "Camera.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>



 /*
namespace Mocha
{

	namespace RenderGlobals
	{
		static const int windowWidth = 2000;
		static const int windowHeight = 1400;

		static GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
		static glm::mat4 projection;
		static Camera camera;

		static GLfloat deltaTime = 0.0f;
		static GLfloat lastTime = 0.0f;
	}

	int RunApplication()
	{
		Logger::Log("Mocha Morning!");

		Window mochaMainWindow = Window(RenderGlobals::windowWidth, RenderGlobals::windowHeight, "wondow");
		RenderGlobals::camera = Camera(glm::vec3(0.0, 0.0, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, 0.0f);


		RenderGlobals::projection = glm::perspective(45.0f, (GLfloat)mochaMainWindow.getBufferWidth() / (GLfloat)mochaMainWindow.getBufferHeight(), 0.1f, 200.0f);
	

		Mocha::Shader shader;
		Mocha::Material mat;
		mat.setShader(&shader);
		Mocha::Mesh mesh = Mocha::GenerateDefaultMesh();
		Mocha::RenderObject object(&mat, &mesh, RenderGlobals::projection, &RenderGlobals::camera);

		Mocha::Shader shader2;
		Mocha::Material mat2;
		mat2.setShader(&shader2);
		Mocha::Mesh mesh2 = Mocha::GenerateDefaultMesh();
		Mocha::RenderObject object2(&mat2, &mesh2, RenderGlobals::projection, &RenderGlobals::camera);



		while (!mochaMainWindow.shouldClose())
		{
			// Compute deltatime variable
			GLfloat currentTime = glfwGetTime();
			deltaTime = currentTime - lastTime;
			lastTime = currentTime;
		}
	
	
	
	
	
	}
}
*/
