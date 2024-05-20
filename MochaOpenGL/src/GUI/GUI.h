#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glfw\glfw3.h>


namespace Mocha
{
	namespace GUI
	{
		void Initiate(GLFWwindow* windowPtr);
		void Destroy();
		void InitiateFrame();

		void Draw();
	}
}