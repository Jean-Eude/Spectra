#include "Headers.h"
#include "Test_02.h"

Scene::Scene()
{

}

GLFWwindow* Scene::onInit()
{
    Window.setupOpenGL(4, 5);
    myWindow = Window.initWindow(width, height, title);
    Window.logWindow(myWindow);
    Window.addWindow(myWindow, width, height);

    Shader.setShader("Core/Assets/Scenes/Test_02 (Shader)/Shaders/default.vert", "Core/Assets/Scenes/Test_02 (Shader)/Shaders/default.frag");
    Quad.setupQuad();
    GUI.onSetupGUI("#version 450", myWindow);
    
    return myWindow;
}

void Scene::onUpdate(GLFWwindow* window)
{
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        GUI.onCreateFrameGUI();

        Shader.useShader();
        Quad.updateQuad();

        ImGui::Begin("My name is window, ImGUI window");
        ImGui::Text("Hello there adventurer!");
        ImGui::End();

        GUI.onRenderFrameGUI();
}



void Scene::onEndUpdate(GLFWwindow* window)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}



void Scene::onClose(GLFWwindow* window)
{
    GUI.onCloseGUI();
    Quad.deleteQuad();
    Shader.deleteShader();
    Window.cleanWindow(window);
}