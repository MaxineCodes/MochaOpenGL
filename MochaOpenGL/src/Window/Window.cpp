#include "Window.h"
#include "../Logging/Logger.h"

Mocha::Window::Window(GLint windowWidth, GLint windowHeight, const char* windowName)
{
	m_width = windowWidth;
	m_height = windowHeight;

	for (size_t i = 0; i < 1024; i++)
	{
		m_keys[i] = 0;
	}

	// Initialise GLFW
	if (!glfwInit())
	{
		Logger::Log("GLFW initialisation failed!", Logger::ERROR);
		glfwTerminate();
		return;
	}

	// Setup GLFW window properties
	// OpenGL version (3.3)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatbility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the window
	m_window = glfwCreateWindow(m_width, m_height, windowName, NULL, NULL);
	if (!m_window)
	{
		Logger::Log("GLFW window creation failed!", Logger::ERROR);
		glfwTerminate();
		return;
	}

	// Get Buffer Size information
	glfwGetFramebufferSize(m_window, &m_bufferWidth, &m_bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(m_window);

	// Handle key inputs
	glfwSetKeyCallback(m_window, handleKeyInput);
	glfwSetCursorPosCallback(m_window, handleMouseInput);

	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{

		Logger::Log("GLEW != GLEW_OK", Logger::ERROR);
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return;
	}


	glEnable(GL_DEPTH_TEST);

	// Setup Viewport size
	glViewport(0, 0, m_bufferWidth, m_bufferHeight);

	glfwSetWindowUserPointer(m_window, this);


}

Mocha::Window::~Window()
{

}

GLfloat Mocha::Window::getXChange()
{
	GLfloat theChange = m_xChange;
	m_xChange = 0.0f;
	return theChange;
}

GLfloat Mocha::Window::getYChange()
{
	GLfloat theChange = m_yChange;
	m_yChange = 0.0f;
	return theChange;
}

void Mocha::Window::handleKeyInput(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->m_keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->m_keys[key] = false;
		}
	}
}

void Mocha::Window::handleMouseInput(GLFWwindow* window, double xPos, double yPos)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->m_mouseFirstMoved)
	{
		theWindow->m_lastX = xPos;
		theWindow->m_lastY = yPos;
		theWindow->m_mouseFirstMoved = false;
	}

	theWindow->m_xChange = xPos - theWindow->m_lastX;
	theWindow->m_yChange = theWindow->m_lastY - yPos;

	theWindow->m_lastX = xPos;
	theWindow->m_lastY = yPos;
}
