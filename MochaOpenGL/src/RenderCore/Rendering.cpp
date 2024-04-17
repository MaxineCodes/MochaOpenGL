
#include "Rendering.h"

// Used in the DeltaTime calculation
static GLfloat lastTime = 0.0f;

int Mocha::Rendering::RunApplication()
{
	Logger::Log("Mocha Morning!");

	// Create a window, which also becomes the active OpenGL viewport
	Window mochaMainWindow = Window(Globals::windowWidth, Globals::windowHeight, "wondow");
	Globals::camera = Camera(glm::vec3(0.0, 0.0, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, 0.0f);

	// Figure out the perspective matrix and store it globally
	float aspectRatio = (GLfloat)mochaMainWindow.getBufferWidth() / (GLfloat)mochaMainWindow.getBufferHeight();
	Globals::projection = CalculatePerspectiveProjectionMatrix(45.0f, aspectRatio, 0.1f, 200.0f);


	// Temporary code to make some objects to render
	Mocha::Shader shader;
	Mocha::Material mat;
	mat.setShader(&shader);
	Mocha::Mesh mesh = Mocha::GenerateDefaultMesh();
	Mocha::RenderObject object(&mat, &mesh, Globals::projection, &Globals::camera);

	Mocha::Shader shader2;
	Mocha::Material mat2;
	mat2.setShader(&shader2);
	Mocha::Mesh mesh2 = Mocha::GenerateDefaultMesh();
	Mocha::RenderObject object2(&mat2, &mesh2, Globals::projection, &Globals::camera);



	while (!mochaMainWindow.shouldClose())
	{
		// Compute deltatime variable
		UpdateDeltaTime();

		// Inputs
		glfwPollEvents();
		Globals::camera.keyControl(mochaMainWindow.getKeyArray(), Globals::deltaTime);
		Globals::camera.mouseControl(mochaMainWindow.getXChange(), mochaMainWindow.getYChange());


		// Clear window with a nice blue shade
		glClearColor(0.4f, 0.7f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Temporary code to render objects
		object.setTranslation(5.0f, 0.0f, -5.0f);
		object.setRotation(0.0f, 0.0f, 45.0f);
		object.setScale(1.2f, 1.2f, 1.2f);
		object.draw();

		object2.setTranslation(5.0f, 0.0f, 5.0f);
		object2.setRotation(0.0f, 45.0f, 0.0f);
		object2.setScale(0.8f, 0.8f, 0.8f);
		object2.draw();


		// Use no shader
		glUseProgram(0);

		// Swap the buffers so the viewport in the window shows the frame
		mochaMainWindow.swapBuffers();
	}




	return 0;
}

void Mocha::Rendering::UpdateDeltaTime()
{
	// Get the time between the last frame and the next frame
	GLfloat currentTime = glfwGetTime();
	Globals::deltaTime = currentTime - lastTime;
	lastTime = currentTime;
}

glm::mat4 Mocha::Rendering::CalculatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearFrustum, float farFrustum)
{
	// A bit verbose to put this in it's own function, but additional functionality might be added one day
	return glm::perspective(fov, aspectRatio, nearFrustum, farFrustum);
}
