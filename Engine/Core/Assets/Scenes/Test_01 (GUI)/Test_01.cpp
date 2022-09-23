#include "Headers.h"
#include "Test_01.h"

Scene::Scene()
{

}

GLFWwindow* Scene::onInit()
{
    // Window Setup
    Window.setupOpenGL(4, 5);
    myWindow = Window.initWindow(width, height, title);
    Window.logWindow(myWindow);
    Window.addWindow(myWindow, width, height);
    
    // GUI Setup
    GUI.onSetupGUI(glsl, myWindow);
    
    return myWindow;
}

void Scene::onUpdate(GLFWwindow* window)
{
    // Clear background and color it
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // GUI onUpdate
    GUI.onCreateFrameGUI();

    ImGui::Begin("My name is window, ImGUI window");
    ImGui::Text("Hello there adventurer!");
    ImGui::End();

    GUI.onRenderFrameGUI();
    // Gui onUpdate End
}

void Scene::onEndUpdate(GLFWwindow* window)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}


void Scene::onClose(GLFWwindow* window)
{
    GUI.onCloseGUI();
    Window.cleanWindow(window);
}