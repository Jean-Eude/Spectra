#include "Headers.h"
#include "Test_09.h"
#include "VarH.h"

void processInput(GLFWwindow* window);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

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


    glfwSetFramebufferSizeCallback(myWindow, framebuffer_size_callback);
    glfwSetScrollCallback(myWindow, scroll_callback);
    glfwSetCursorPosCallback(myWindow, mouse_callback);


    // ---------------------------------- //
    // ----- Shaders Initialization ----- //
    // ---------------------------------- //

    Shader.setShader("Core/Assets/Scenes/Test_09 (Textured Model)/Shaders/default.vert", "Core/Assets/Scenes/Test_09 (Textured Model)/Shaders/default.frag");
    Shader.setBind4f("color", color[0], color[1], color[2], color[3]);
    Shader.setBind1f("view", FOVcamkey);

    // ---------------------------------- //
    // ----- Texture Initialization ----- //
    // ---------------------------------- //

    Texture.setTexture("Core/Assets/Scenes/Test_09 (Textured Model)/Textures/diffuse.jpg", "diffuse", true);

    // ---------------------------------- //
    // ------ Shape Initialization ------ //
    // ---------------------------------- //

    Model.loadModel("Core/Assets/Scenes/Test_09 (Textured Model)/Models/backpack.obj");

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
    // per-frame time logic
    // --------------------
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // Input
    processInput(window);

    //Texture
    glActiveTexture(GL_TEXTURE0);
    Texture.useTexture();
    Shader.setBindTexture("diffuse", 0);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Gui.onCreateFrameGUI();
    Shader.useShader();
    Camera.Setup(width, height, cameraPos, cameraFront, cameraUp, true, true, true, translatePos, scale, axesRotate, rotation, FOVcamkey, Shader);
    Model.Draw();


    ImGui::Begin("Tests modifications");
    ImGui::Text("Exemple");
    ImGui::SliderFloat("FOV", &FOVcamkey, 0.0f, 90.0f);
    ImGui::End();


    Shader.useShader();
    Shader.setBind1f("view", FOVcamkey);

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


void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}



void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    FOVcamkey -= (float)yoffset;
    if (FOVcamkey < 1.0f)
        FOVcamkey = 1.0f;
    if (FOVcamkey > 180.0f)
        FOVcamkey = 180.0f;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float cameraSpeed = static_cast<float>(2.5 * deltaTime);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    

    // Shift acceleration

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            cameraPos += cameraSpeed * cameraFront * 4.0f;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            cameraPos -= cameraSpeed * cameraFront * 4.0f;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * 4.0f;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * 4.0f;
    }
        
}