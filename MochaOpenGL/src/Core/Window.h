#pragma once

#include <gl\glew.h>
#include <glfw\glfw3.h>

namespace Mocha
{

	class Window
	{
	public:

		Window(GLint windowWidth, GLint windowHeight, const char* windowName);

		~Window();

		GLint getBufferWidth() { return bufferWidth; }
		GLint getBufferHeight() { return bufferHeight; }

		bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }

		bool* getKeyArray() { return keys; }
		GLfloat getXChange();
		GLfloat getYChange();

		void swapBuffers() { glfwSwapBuffers(mainWindow); }

	private:

		GLFWwindow* mainWindow;

		const char* windowName = "Default Window";

		GLint width = 400, height = 400;
		GLint bufferWidth = 0, bufferHeight = 0;

		bool keys[1024];

		GLfloat lastX = 0, lastY = 0, xChange = 0, yChange = 0;
		bool mouseFirstMoved = false;

		static void handleKeyInput(GLFWwindow* window, int key, int code, int action, int mode);
		static void handleMouseInput(GLFWwindow* window, double xPos, double yPos);

	};

}

