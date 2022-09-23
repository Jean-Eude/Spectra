#ifndef QUAD2D_H
#define QUAD2D_H

#include "../Utils/Headers.h"


class Quad2D
{
public:
	Quad2D();
	void setupQuad2D();
	void updateQuad2D();
	void deleteQuad2D();
private:
	GLuint VAO, VBO, EBO;
};

#endif