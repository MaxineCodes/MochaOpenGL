#pragma once

#include "..\Logging\Logger.h"

#include "../Window/Window.h"
#include "RenderObjects/RenderObject.h"
#include "Camera.h"
#include "Lights/Light.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "../GUI/GUI.h"



namespace Mocha
{

	namespace Rendering
	{
		namespace Uniforms
		{
			// Store all uniforms here

			inline GLuint

				uniformProjection = 0,
				uniformModel = 0,
				uniformView = 0,

				uniformEyePosition = 0, // Camera position

				uniformAmbientIntensity = 0,
				uniformAmbientColour = 0,
				uniformDirection = 0,
				uniformDiffuseIntensity = 0,

				uniformSpecularIntensity = 0,
				uniformSpecularShininess = 0;

		}

		namespace Globals
		{
			// Persistant variables which are handy to have globally accessible

			inline const int windowWidth = 2000;
			inline const int windowHeight = 1400;

			inline glm::mat4 projectionMatrix;
			inline Camera camera;

			inline GLfloat deltaTime = 0.0f;
		}

		// Starts the program
		int RunApplication();

		// Calculate delta time
		void UpdateDeltaTime();
		
		// Calculate the perspective matrix
		glm::mat4 CalculatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearFrustum, float farFrustum);

	}
}
