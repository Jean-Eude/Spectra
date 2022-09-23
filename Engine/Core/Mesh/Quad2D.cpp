#include "Headers.h"
#include "Quad2D.h"


Quad2D::Quad2D()
{

}

void Quad2D::setupQuad2D()
{
	GLfloat vertices[] =
	{	//     COORDINATES     /        COLORS        /    TexCoord    /       NORMALS     //
    	1.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,	0.0f, 0.0f, 1.0f,  // top right
     	1.0f, -1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,	0.0f, 0.0f, 1.0f,  // bottom right
    	-1.0f, -1.0f, 0.0f,  1.0f, 0.0f, 0.0f,   0.0f, 0.0f,	0.0f, 0.0f, 1.0f,  // bottom left
    	-1.0f,  1.0f, 0.0f,  1.0f, 0.0f, 0.0f,   0.0f, 1.0f,	0.0f, 0.0f, 1.0f   // top left 
	};

	GLuint indices[] =
	{
    	0, 1, 3,   // first triangle
    	1, 2, 3    // second triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(2);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Quad2D::updateQuad2D()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


void Quad2D::deleteQuad2D()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}