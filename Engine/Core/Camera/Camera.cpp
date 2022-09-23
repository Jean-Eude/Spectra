#include "Headers.h"
#include "Camera.h"


Camera::Camera()
{

}


void Camera::Setup(int width, int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, bool translate, bool scale, bool rotate, glm::vec3 translatePos, glm::vec3 Scale, glm::vec3 Rotation, float angleRotation, float FOV, Shader myShader)
{
    // Initializes matrices so they are not the null matrix
    this->model = glm::mat4(1.0f);
    this->view = glm::mat4(1.0f);
    this->proj = glm::mat4(1.0f);

    // Assigns different transformations to each matrix
    if (translate == true)
    {
        model = glm::translate(model, translatePos);
    }
    if (scale == true)
    {
        model = glm::scale(model, Scale); // a smaller cube
    }
    if (rotate == true)
    {
        model = glm::rotate(model, glm::radians(angleRotation), Rotation);
    }

    this->model = glm::rotate(this->model, glm::radians(0.0f), glm::vec3(1.0f, 0.3f, 5.0f));
    this->view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    this->proj = glm::perspective(glm::radians(FOV), (float)width / (float)height, 0.1f, 100.0f);

    myShader.setBind4fv("model", 1, GL_FALSE, glm::value_ptr(this->model));
    myShader.setBind4fv("view", 1, GL_FALSE, glm::value_ptr(this->view));
    myShader.setBind4fv("proj", 1, GL_FALSE, glm::value_ptr(this->proj));
}


