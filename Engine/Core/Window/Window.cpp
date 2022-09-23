#include "Headers.h"
#include "Window.h"


Window::Window()
{

}


void Window::setupOpenGL(int major, int minor)
{
    glfwInit();

    spdlog::default_logger()->info("Loaded GLFW {}", glfwGetVersionString());

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}


GLFWwindow* Window::initWindow(int width, int height, const char* title)
{
    GLFWwindow* myWindow;
    myWindow = glfwCreateWindow(width, height, title, NULL, NULL);
   
    return myWindow;
}


int Window::logWindow(GLFWwindow* window)
{
    if (window == NULL)
    {
        spdlog::error("Window failed to Initialized !", 1);
        glfwTerminate();
        return -1;
    }
    else
    {
        spdlog::info("Window Initialized !");
        return 0;
    }
}


void Window::addWindow(GLFWwindow* window, int width, int height)
{
    glfwMakeContextCurrent(window);
    gladLoadGL(); //OpenGL Functions
    glfwSetWindowAspectRatio(window, 16, 9);
}


void Window::cleanWindow(GLFWwindow* window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
}