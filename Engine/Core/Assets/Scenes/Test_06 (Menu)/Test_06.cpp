#include "Headers.h"
#include "Test_06.h"
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

    Gui.onSetupGUI("#version 450", myWindow);
    
    return myWindow;
}



void Scene::onUpdate(GLFWwindow* window)
{
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Gui.onCreateFrameGUI();

        if(ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("Options"))
            {

                if (ImGui::BeginMenu("Window"))
                {
                    ImGui::Checkbox("Show Datas", &showdatas);
                    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

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
    Window.cleanWindow(window);
}