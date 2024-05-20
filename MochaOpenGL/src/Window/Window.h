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

		GLFWwindow* getWindowPtr();
		GLint getBufferWidth() { return m_bufferWidth; }
		GLint getBufferHeight() { return m_bufferHeight; }

		bool shouldClose() { return glfwWindowShouldClose(m_window); }

		bool* getKeyArray() { return m_keys; }
		GLfloat getXChange();
		GLfloat getYChange();

		void swapBuffers() { glfwSwapBuffers(m_window); }


	private:
		GLFWwindow* m_window;

		const char* m_windowName = "Default Window";

		GLint m_width = 400, m_height = 400;
		GLint m_bufferWidth = 0, m_bufferHeight = 0;

		bool m_keys[1024];

		GLfloat m_lastX = 0, m_lastY = 0, m_xChange = 0, m_yChange = 0;
		bool m_mouseFirstMoved = false;

		static void handleKeyInput(GLFWwindow* window, int key, int code, int action, int mode);
		static void handleMouseInput(GLFWwindow* window, double xPos, double yPos);

	};

}

