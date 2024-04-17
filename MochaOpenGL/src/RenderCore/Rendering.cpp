
#include "Rendering.h"

// Used in the DeltaTime calculation
static GLfloat lastTime = 0.0f;

int Mocha::RunApplication()
{
	Logger::Log("Mocha Morning!");

	Window mochaMainWindow = Window(RenderGlobals::windowWidth, RenderGlobals::windowHeight, "wondow");
	RenderGlobals::camera = Camera(glm::vec3(0.0, 0.0, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, 0.0f);


	RenderGlobals::projection = glm::perspective(45.0f, (GLfloat)mochaMainWindow.getBufferWidth() / (GLfloat)mochaMainWindow.getBufferHeight(), 0.1f, 200.0f);


	Mocha::Shader shader;
	Mocha::Material mat;
	mat.setShader(&shader);
	Mocha::Mesh mesh = Mocha::GenerateDefaultMesh();
	Mocha::RenderObject object(&mat, &mesh, RenderGlobals::projection, &RenderGlobals::camera);

	Mocha::Shader shader2;
	Mocha::Material mat2;
	mat2.setShader(&shader2);
	Mocha::Mesh mesh2 = Mocha::GenerateDefaultMesh();
	Mocha::RenderObject object2(&mat2, &mesh2, RenderGlobals::projection, &RenderGlobals::camera);



	while (!mochaMainWindow.shouldClose())
	{
		// Compute deltatime variable
		updateDeltaTime();

		// Inputs
		glfwPollEvents();
		RenderGlobals::camera.keyControl(mochaMainWindow.getKeyArray(), RenderGlobals::deltaTime);
		RenderGlobals::camera.mouseControl(mochaMainWindow.getXChange(), mochaMainWindow.getYChange());


		// Clear window with a nice blue shade
		glClearColor(0.4f, 0.7f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		RenderGlobals::uniformModel = shader.getModelMatrixLocation();
		RenderGlobals::uniformProjection = shader.getProjectionMatrixLocation();
		RenderGlobals::uniformView = shader.getViewMatrixLocation();

		object.setTranslation(0.0f, 0.0f, -5.0f);
		object.setRotation(0.5f, 0.5f, 0.5f);
		object.setScale(1.2f, 1.2f, 1.2f);

		object.draw();

		RenderGlobals::uniformModel = shader.getModelMatrixLocation();
		RenderGlobals::uniformProjection = shader.getProjectionMatrixLocation();
		RenderGlobals::uniformView = shader.getViewMatrixLocation();

		object2.setTranslation(0.0f, 0.0f, 5.0f);
		object2.setRotation(0.0f, 0.0f, 0.0f);
		object2.setScale(0.8f, 0.8f, 0.8f);

		object2.draw();


		glUseProgram(0);

		mochaMainWindow.swapBuffers();
	}




	return 0;
}

void Mocha::updateDeltaTime()
{
	// Get the time between the last frame and the next frame
	GLfloat currentTime = glfwGetTime();
	RenderGlobals::deltaTime = currentTime - lastTime;
	lastTime = currentTime;
}
