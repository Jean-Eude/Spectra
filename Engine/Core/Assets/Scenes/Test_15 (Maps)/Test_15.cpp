#include "Headers.h"
#include "Test_15.h"
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

    lightingShader.setShader("Core/Assets/Scenes/Test_15 (Maps)/Shaders/colors.vert", "Core/Assets/Scenes/Test_15 (Maps)/Shaders/colors.frag");
    lightCubeShader.setShader("Core/Assets/Scenes/Test_15 (Maps)/Shaders/light_cube.vert", "Core/Assets/Scenes/Test_15 (Maps)/Shaders/light_cube.frag");

    // ---------------------------------- //
    // ----- Texture Initialization ----- //
    // ---------------------------------- //

    TextureBase.setTexture("Core/Assets/Scenes/Test_15 (Maps)/Textures/container2.png", "diffuse", true);
    TextureSpec.setTexture("Core/Assets/Scenes/Test_15 (Maps)/Textures/container_specular.png", "specular", true);

    // ---------------------------------- //
    // ------ Shape Initialization ------ //
    // ---------------------------------- //

    lightCube.setupCube();

    Model.loadModel("Core/Assets/Scenes/Test_15 (Maps)/Models/cube.obj");

    // ---------------------------------- //
    // ------- Gui Initialization ------- //
    // ---------------------------------- //

    Gui.onSetupGUI("#version 450", myWindow);

    // ---------------------------------- //
    // ------------- Extras ------------- //
    // ---------------------------------- //

    lightingShader.useShader();
    lightingShader.setBindTexture("diffuse", 0);
    lightingShader.setBindTexture("specular", 1);


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
    TextureBase.useTexture();
    glActiveTexture(GL_TEXTURE1);
    TextureSpec.useTexture();

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Gui.onCreateFrameGUI();

    lightingShader.useShader();
    lightingShader.setBind3f("light.position", lightPos);
    lightingShader.setBind3f("viewPos", cameraPos);
    lightingShader.setBind3f("light.ambient", 0.2f, 0.2f, 0.2f);
    lightingShader.setBind3f("light.diffuse", 0.5f, 0.5f, 0.5f);
    lightingShader.setBind3f("light.specular", 1.0f, 1.0f, 1.0f);
    lightingShader.setBind1f("material.shininess", 64.0f);


    lightingShader.setBindTexture("diffuse", 0);
    lightingShader.setBindTexture("specular", 1);
    
    Camera.Setup(width, height, cameraPos, cameraFront, cameraUp, false, true, false, translatePos, scale, axesRotate, rotation, FOVcamkey, lightingShader);
    Model.Draw();


    lightCubeShader.useShader();
    Camera.Setup(width, height, cameraPos, cameraFront, cameraUp, true, true, false, translatePos, scale, axesRotate, rotation, FOVcamkey, lightCubeShader);
    lightCube.updateCube();
    

    ImGui::Begin("Tests modifications");
    ImGui::Text("Exemple");
    ImGui::SliderFloat("FOV", &FOVcamkey, 0.0f, 90.0f);
    ImGui::End();


    lightingShader.useShader();
    lightingShader.setBind3f("objectColor", 1.0f, 0.5f, 0.31f);
    lightingShader.setBind3f("lightColor", 1.0f, 1.0f, 1.0f);
    lightingShader.setBindTexture("diffuse", 0);
    lightCubeShader.useShader();
    

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
    lightingShader.deleteShader();
    lightCubeShader.deleteShader();
    Cube.deleteCube();
    lightCube.deleteCube();
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