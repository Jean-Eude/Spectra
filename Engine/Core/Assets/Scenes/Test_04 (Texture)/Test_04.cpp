#include "Headers.h"
#include "Test_04.h"
#include "VarH.h"


Scene::Scene()
{

}


GLFWwindow* Scene::onInit()
{
    // ---------------------------------- //
    // --------- Initialization --------- //
    // ---------------------------------- //

    Window.setupOpenGL(4, 5);
    myWindow = Window.initWindow(width, height, title);
    Window.logWindow(myWindow);
    Window.addWindow(myWindow, width, height);

    // ---------------------------------- //
    // ----- Shaders Initialization ----- //
    // ---------------------------------- //

    Shader.setShader("Core/Assets/Scenes/Test_04 (Texture)/Shaders/default.vert", "Core/Assets/Scenes/Test_04 (Texture)/Shaders/default.frag");
    Shader.setBind1f("size", size);

    // ---------------------------------- //
    // ----- Texture Initialization ----- //
    // ---------------------------------- //
    
    Texture.setTexture("Core/Assets/Scenes/Test_04 (Texture)/Texture/wall.jpg", "ironAlbedo", true);

    // ---------------------------------- //
    // ------ Shape Initialization ------ //
    // ---------------------------------- //

    Quad.setupQuad();
    Triangle.setupTriangle();
    
    // ---------------------------------- //
    // ------- Gui Initialization ------- //
    // ---------------------------------- //

    Gui.onSetupGUI("#version 450", myWindow);


    return myWindow;
}



void Scene::onUpdate(GLFWwindow* window)
{
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        Texture.useTexture();
        Shader.setBindTexture("texWall", 0);

        Gui.onCreateFrameGUI();
        Shader.useShader();

        if (drawQuad)
            Quad.updateQuad();
        if (drawTriangle)
            Triangle.updateTriangle();

        ImGui::Begin("Tests modifications");
        ImGui::Text("Exemple");
        ImGui::SliderFloat("Size", &size, 0.5f, 2.0f);
        ImGui::Checkbox("Draw Quad", &drawQuad);
        ImGui::Checkbox("Draw Triangle", &drawTriangle);
        ImGui::End();

        Shader.useShader();
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