#include "Headers.h"
#include "Plane.h"


Plane::Plane()
{

}

void Plane::setupPlane(unsigned int X_SEGMENTS, unsigned int Y_SEGMENTS)
{
    for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
    {
        for (unsigned int y = 0; y <= Y_SEGMENTS; ++y)
        {
            float xSegment = (float)x;  //  / = tesselation  * = agrandissement de chaque triangle  x = ((float)x + (float)X_SEGMENTS) y = ...
            float ySegment = (float)y;
            float xPos = xSegment;
            float yPos = ySegment;
            float zPos = 1.0f;

            this->positions.push_back(glm::vec3(xPos, yPos, zPos));
            this->uv.push_back(glm::vec2(xSegment, ySegment));
            this->normals.push_back(glm::vec3(xPos, yPos, zPos));
        }
    }

    oddRow = false;

    for (unsigned int y = 0; y < Y_SEGMENTS; ++y)
    {
        if (!oddRow) // even rows: y == 0, y == 2; and so on
        {
            for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
            {
                this->indices.push_back(y * (X_SEGMENTS + 1) + x);
                this->indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
            }
        }
        else
        {
            for (int x = X_SEGMENTS; x >= 0; --x)
            {
                this->indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
                this->indices.push_back(y * (X_SEGMENTS + 1) + x);
            }
        }
        oddRow = !oddRow;
    }

    indexCount = static_cast<unsigned int>(this->indices.size());

    for (unsigned int i = 0; i < positions.size(); ++i)
    {
        this->data.push_back(this->positions[i].x);
        this->data.push_back(this->positions[i].y);
        this->data.push_back(this->positions[i].z);
        if (this->normals.size() > 0)
        {
            this->data.push_back(this->normals[i].x);
            this->data.push_back(this->normals[i].y);
            this->data.push_back(this->normals[i].z);
        }
        if (uv.size() > 0)
        {
            this->data.push_back(this->uv[i].x);
            this->data.push_back(this->uv[i].y);
        }
    }

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(unsigned int), &this->indices[0], GL_STATIC_DRAW);

    stride = (3 + 2 + 3) * sizeof(float);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}


void Plane::updatePlane()
{
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLE_STRIP, this->indexCount, GL_UNSIGNED_INT, 0);
}


void Plane::deletePlane()
{
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
}

void Plane::drawPolygons(GLenum mode)
{
    glPolygonMode(GL_FRONT_AND_BACK, mode);
}


