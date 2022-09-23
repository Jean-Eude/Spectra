#ifndef QUAD_H
#define QUAD_H

#include "../Utils/Headers.h"


class Quad
{
public:
	Quad();
	void setupQuad();
	void updateQuad();
	void deleteQuad();
private:
	GLuint VAO, VBO, EBO;
};

#endif