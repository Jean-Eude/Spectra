#include "Headers.h"
#include "Test_03.h"
#include "VarH.h"

Scene::Scene()
{

}


GLFWwindow* Scene::onInit()
{
    Window.setupOpenGL(4, 5);
    myWindow = Window.initWindow(width, height, title);
    Window.logWindow(myWindow);
    Window.addWindow(myWindow, width, height);

    Shader.setShader("Source/Assets/Scenes/Test_03/Shaders/default.vert", "Source/Assets/Scenes/Test_03/Shaders/default.frag");
    Shader.setBind4f("color", color[0], color[1], color[2], color[3]);
    Shader.setBind1f("size", size);

    Quad.setupQuad();
    Triangle.setupTriangle();

    Gui.onSetupGUI("#version 450", myWindow);
    
    return myWindow;
}



void Scene::onUpdate(GLFWwindow* window)
{
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Gui.onCreateFrameGUI();
        Shader.useShader();
        Shader.setBind4f("color", color[0], color[1], color[2], color[3]);
        Shader.setBind1f("size", size);

        if (drawQuad)
            Quad.updateQuad();
        if (drawTriangle)
            Triangle.updateTriangle();

        ImGui::Begin("Tests modifications");
        ImGui::Text("Exemple");
        ImGui::ColorEdit4("Color", color);
        ImGui::SliderFloat("Size", &size, 0.5f, 2.0f);
        ImGui::Checkbox("Draw Quad", &drawQuad);
        ImGui::Checkbox("Draw Triangle", &drawTriangle);
        ImGui::End();

        Shader.useShader();
        Shader.setBind4f("color", color[0], color[1], color[2], color[3]);
        Shader.setBind1f("size", size);
        Gui.onRenderFrameGUI();
}



void Scene::onEndUpdate(GLFWwindow* window)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}



void Scene::onClose(GLFWwindow* window)
{
    Gui.onCloseGUI();
    Quad.deleteQuad();
    Triangle.deleteTriangle();
    Shader.deleteShader();
    Window.cleanWindow(window);
}