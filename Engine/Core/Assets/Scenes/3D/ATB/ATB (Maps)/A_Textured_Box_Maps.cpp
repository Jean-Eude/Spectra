#include "Headers.h"
#include "A_Textured_Box_Maps.h"
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

    BoxShader.setShader("Core/Assets/Scenes/3D/ATB/ATB (Maps)/Shaders/colors.vert", "Core/Assets/Scenes/3D/ATB/ATB (Maps)/Shaders/colors.frag");
    LightShader.setShader("Core/Assets/Scenes/3D/ATB/ATB (Maps)/Shaders/light_cube.vert", "Core/Assets/Scenes/3D/ATB/ATB (Maps)/Shaders/light_cube.frag");

    // ---------------------------------- //
    // ----- Texture Initialization ----- //
    // ---------------------------------- //

    Diffuse.setTexture("Core/Assets/Scenes/3D/ATB/ATB (Maps)/Textures/BrickWall_Diff.png", "diff", true);
    Specular.setTexture("Core/Assets/Scenes/3D/ATB/ATB (Maps)/Textures/BrickWall_Spec.png", "spec", true);

    // ---------------------------------- //
    // ------ Shape Initialization ------ //
    // ---------------------------------- //

    Floor.setupPlane(10, 10);
    Wall_Back.setupPlane(10, 10);
    Wall_Left.setupPlane(10, 10);

    LightSphere.setupSphere(50, 50);

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

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    Gui.onCreateFrameGUI();


    //Texture
    BoxShader.useShader();

    glActiveTexture(GL_TEXTURE0);
    BoxShader.setBindTexture("diffuse", 0);
    Diffuse.useTexture();
    glActiveTexture(GL_TEXTURE1);
    BoxShader.setBindTexture("specular", 1);
    Specular.useTexture();

    BoxShader.setBind3f("viewPos", cameraPos);
    BoxShader.setBind3f("light.position", translateSphere);

    BoxShader.setBind3f("light.ambient", 0.2f, 0.2f, 0.2f);
    BoxShader.setBind3f("light.diffuse", 0.5f, 0.5f, 0.5f);
    BoxShader.setBind3f("light.specular", 1.0f, 1.0f, 1.0f);

    BoxShader.setBind1f("material.shininess", shininess);
    BoxShader.setBind1f("SpecStrength", specStrength);
    BoxShader.setBind1f("tilling", tiletex);


    //Floor Settings
    Camera.Setup(width, height, cameraPos, cameraFront, cameraUp, true, false, true, translateFloor, scaleFloor, axesFloor, angleFloor, FOVcamkey, BoxShader);
    Floor.updatePlane();


    //Walls Settings
    Camera.Setup(width, height, cameraPos, cameraFront, cameraUp, true, false, false, translateWall_Back, scaleWall_Back, axesWall_Back, angleWall_Back, FOVcamkey, BoxShader);
    Wall_Back.updatePlane();

    Camera.Setup(width, height, cameraPos, cameraFront, cameraUp, true, false, false, translateWall_Left, scaleWall_Left, axesWall_Left, angleWall_Left, FOVcamkey, BoxShader);
    Wall_Left.updatePlane();


    //LightSphere Setting
    LightShader.useShader();
    Camera.Setup(width, height, cameraPos, cameraFront, cameraUp, true, false, true, translateSphere, scaleSphere, axesSphere, angleSphere, FOVcamkey, LightShader);
    LightSphere.updateSphere();
    

    ImGui::Begin("Properties");
    ImGui::Text("Light Properties");
    ImGui::Text("Position");
    ImGui::SliderFloat("xLight", &translateSphere[0], -20.0f, 20.0f);  ImGui::SliderFloat("yLight", &translateSphere[1], -20.0f, 20.0f);  ImGui::SliderFloat("zLight", &translateSphere[2], -20.0f, 20.0f);
    ImGui::Spacing();
    ImGui::Text("Rotation");
    ImGui::SliderFloat("xRotLight", &axesSphere[0], -10.0f, 10.0f);  ImGui::SliderFloat("yRotLight", &axesSphere[1], -10.0f, 10.0f);  ImGui::SliderFloat("zRotLight", &axesSphere[2], -10.0f, 10.0f);
    ImGui::Spacing();
    ImGui::Text("Texture Properties");
    ImGui::Text("All");
    ImGui::SliderFloat("Tilling UV", &tiletex, -1.0f, 1.0f);
    ImGui::Text("Specular");
    ImGui::SliderInt("Shininess", &shininess, 1, 256);
    ImGui::SliderFloat("Specular Strength", &specStrength, 0.0f, 1.0f);
    ImGui::End();


    BoxShader.useShader();
    BoxShader.setBind3f("viewPos", cameraPos);
    BoxShader.setBind3f("lightPos", translateSphere);

    BoxShader.setBind3f("light.ambient", 0.2f, 0.2f, 0.2f);
    BoxShader.setBind3f("light.diffuse", 0.5f, 0.5f, 0.5f);
    BoxShader.setBind3f("light.specular", 1.0f, 1.0f, 1.0f);

    BoxShader.setBind1f("material.shininess", shininess);
    BoxShader.setBind1f("SpecStrength", specStrength);
    BoxShader.setBind1f("tilling", tiletex);


    LightShader.useShader();

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
    BoxShader.deleteShader();
    LightShader.deleteShader();

    Floor.deletePlane();
    Wall_Back.deletePlane();

    LightSphere.deleteSphere();

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