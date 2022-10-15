#ifndef _WINDOW_H_
#define _WINDOW_H_

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