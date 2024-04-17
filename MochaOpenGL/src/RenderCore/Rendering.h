#pragma once

#include "..\Logging\Logger.h"

#include "../Window/Window.h"
#include "RenderObject.h"
#include "Camera.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>




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
	}

	// Starts the program
	int RunApplication();

	// Calculate delta time
	void updateDeltaTime();
}
