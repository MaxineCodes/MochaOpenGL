#include "Logging/Logger.h"
#include "Core/Window.h"


int main()
{
	Mocha::Logger::Log("Good Morning!");

	Mocha::Window mainWindow = Mocha::Window(2000, 1400, "wondow");

	while (!mainWindow.getShouldClose())
	{
		glfwPollEvents();

		// Clear window
		glClearColor(0.4f, 0.7f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mainWindow.swapBuffers();
	}




	return 0;
}