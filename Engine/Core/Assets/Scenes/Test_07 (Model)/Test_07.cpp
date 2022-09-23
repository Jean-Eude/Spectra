#include "Headers.h"
#include "Test_07.h"
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

    Shader.setShader("Core/Assets/Scenes/Test_07 (Model)/Shaders/default.vert", "Core/Assets/Scenes/Test_07 (Model)/Shaders/default.frag");
    Shader.setBind4f("color", color[0], color[1], color[2], color[3]);
    Shader.setBind1f("view", FOV);

    // ---------------------------------- //
    // ----- Texture Initialization ----- //
    // ---------------------------------- //



    // ---------------------------------- //
    // ------ Shape Initialization ------ //
    // ---------------------------------- //

    Model.loadModel("Core/Assets/Scenes/Test_07 (Model)/Models/teapot.obj");

    // ---------------------------------- //
    // ------- Gui Initialization ------- //
    // ---------------------------------- //

    Gui.onSetupGUI("#version 450", myWindow);

    // ---------------------------------- //
    // ------------- Extras ------------- //
    // ---------------------------------- //

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    return myWindow;
}



void Scene::onUpdate(GLFWwindow* window)
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Gui.onCreateFrameGUI();
    Shader.useShader();


    double crntTime = glfwGetTime();
    if (crntTime - prevTime >= 1 / 60)
    {
        rotation += 0.0f;
        prevTime = crntTime;
    }

    Matrix.PPMatrix(rotation, width, height, FOV, Shader);
    Model.Draw();


    ImGui::Begin("Tests modifications");
    ImGui::Text("Exemple");
    ImGui::ColorEdit4("Color", color);
    ImGui::SliderFloat("FOV", &FOV, -10.0f, 10.0f);
    ImGui::End();


    Shader.useShader();
    Shader.setBind4f("color", color[0], color[1], color[2], color[3]);
    Shader.setBind1f("view", FOV);

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
    Shader.deleteShader();
    Window.cleanWindow(window);
}