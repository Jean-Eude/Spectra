#ifndef WINDOW_H
#define WINDOW_H

#include "../Utils/Headers.h"

class Window
{
	public:
		Window();
		void setupOpenGL(int major, int minor);
		GLFWwindow* initWindow(int width, int height, const char* title);
		int logWindow(GLFWwindow* window);
		void addWindow(GLFWwindow* window, int width, int height);
		void cleanWindow(GLFWwindow* window);
};

#endif