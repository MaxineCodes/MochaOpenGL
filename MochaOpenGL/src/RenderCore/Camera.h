#pragma once

#include <GL\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

namespace Mocha
{
	class Camera
	{
	public:
		Camera();
		Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch);
		~Camera();

		void keyControl(bool* keysArray, GLfloat deltaTime);
		void mouseControl(GLfloat xChange, GLfloat yChange);

		glm::mat4 calculateViewMatrix();


	private:

		glm::vec3 position;
		glm::vec3 front;
		glm::vec3 up;
		glm::vec3 right;
		glm::vec3 worldUp;

		GLfloat yaw;
		GLfloat pitch;

		GLfloat movementSpeed = 5.0f;
		GLfloat turnSpeed = 0.08f;

		void update();


	};
}

