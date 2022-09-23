#include "Headers.h"
#include "Matrix.h"


Matrix::Matrix()
{

}


void Matrix::PPMatrix(float rotation, int width, int height, float FOV, Shader myShader)
{
    // Initializes matrices so they are not the null matrix
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::mat4(1.0f);

    // Assigns different transformations to each matrix
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, FOV));
    proj = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f); 

    myShader.setBind4fv("model", 1, GL_FALSE, glm::value_ptr(model));
    myShader.setBind4fv("view", 1, GL_FALSE, glm::value_ptr(view));
    myShader.setBind4fv("proj", 1, GL_FALSE, glm::value_ptr(proj));        
}