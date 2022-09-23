#include "Headers.h"
#include "Test_00.h"


Scene::Scene()
{

}

GLFWwindow* Scene::onInit()
{
    Window.setupOpenGL(4, 5);
    myWindow = Window.initWindow(width, height, title);
    Window.logWindow(myWindow);
    Window.addWindow(myWindow, width, height);
    return myWindow;
}

void Scene::onUpdate(GLFWwindow* window)
{

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::onEndUpdate(GLFWwindow* window)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}


void Scene::onClose(GLFWwindow* window)
{
    Window.cleanWindow(window);
}