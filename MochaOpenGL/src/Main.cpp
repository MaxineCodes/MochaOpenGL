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


// Entrypoint (Duh)
int main()
{
	Mocha::Logger::Log("Good Morning!");

	const int windowWidth = 2000;
	const int windowHeight = 1400;

	Mocha::Window mochaMainWindow = Mocha::Window(windowWidth, windowHeight, "wondow");


	// Main loop
	while (!mochaMainWindow.getShouldClose())
	{
		glfwPollEvents();

		// Clear window with a nice blue shade
		glClearColor(0.4f, 0.7f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mochaMainWindow.swapBuffers();
	}


	return 0;
}