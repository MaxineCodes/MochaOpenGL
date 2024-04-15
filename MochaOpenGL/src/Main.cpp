/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	                     - M O C H A OpenGL -
//	 ~                 Realtime OpenGL Renderer;                 ~
//
//	MochaOpenGL is a simple rendering engine toy project.
// 
//>------------------------------------------------------------------------------------------
// 
//  Description:  MochaOpenGL is a simple rendering engine toy project.
//                It's my first proper attempt at a realtime renderer. 
// 
//                This OpenGL renderer is not particularely efficient or feature-rich.
//                It is a learning exersize after all. :) 
// 
// 
//  Dependencies: *OpenGL
//                *GLEW
//                *GLFW
//                *GLM
// 
//>------------------------------------------------------------------------------------------
//  
//  Starting date: 15/04/2024 
//  
//	Credits: Maxine Meijboom
//           [github.com/MaxineCodes]
//           [linkedin.com/in/maxinemeijboom]
//  
/////////////////////////////////////////////////////////////////////////////////////////////


// I like to keep my main.cpp minimal and simple, so there isn't much to see here. ^^;


#include "Logging/Logger.h"
#include "Window/Window.h"
#include "RenderCore/Rendering.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

Mocha::Camera camera;

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

// Entrypoint (Duh)
int main()
{
	Mocha::Logger::Log("Mocha Morning!");

	const int windowWidth = 2000;
	const int windowHeight = 1400;

	Mocha::Window mochaMainWindow = Mocha::Window(windowWidth, windowHeight, "wondow");


	Mocha::Material mat;
	Mocha::Mesh mesh = Mocha::GenerateDefaultMesh();
	Mocha::RenderObject object(&mat, &mesh);

	Mocha::Shader shader;

	camera = Mocha::Camera(glm::vec3(0.0, 0.0, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, 0.0f);

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mochaMainWindow.getBufferWidth() / (GLfloat)mochaMainWindow.getBufferHeight(), 0.1f, 200.0f);


	// Main loop
	while (!mochaMainWindow.shouldClose())
	{
		GLfloat currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;


		glfwPollEvents();

		camera.keyControl(mochaMainWindow.getKeyArray(), deltaTime);
		camera.mouseControl(mochaMainWindow.getXChange(), mochaMainWindow.getYChange());


		// Clear window with a nice blue shade
		glClearColor(0.4f, 0.7f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		shader.useShader();


		uniformModel = shader.getModelMatrixLocation();
		uniformProjection = shader.getProjectionMatrixLocation();
		uniformView = shader.getViewMatrixLocation();


		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));


		glm::mat4 model(1.0f);
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
		model = glm::rotate(model, 1.57f, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));


		//object.transform(uniformModel, model);

		//object.translate(0.0f, 0.0f, -5.0f);
		//object.scale(0.4f, 0.4f, 0.4f);

		object.draw(uniformModel);


		glUseProgram(0);

		mochaMainWindow.swapBuffers();
	}


	return 0;
}