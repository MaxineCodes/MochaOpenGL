#pragma once

#include "..\Logging\Logger.h"

#include "../Window/Window.h"
#include "RenderObjects/RenderObject.h"
#include "Camera.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>




namespace Mocha
{

	namespace Rendering
	{

		namespace Globals
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
		void UpdateDeltaTime();
		
		// Calculate the perspective matrix
		glm::mat4 CalculatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearFrustum, float farFrustum);

	}
}
