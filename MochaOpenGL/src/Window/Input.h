#pragma once

#include "Window.h"

namespace Mocha
{
	namespace Input
	{
		void SetActiveWindow(Window* window);

		void HandleInput(float deltaTime);

		void MouseInput();

		void KeyInput(float deltaTime);

		Window* activeWindow;

	}
}
