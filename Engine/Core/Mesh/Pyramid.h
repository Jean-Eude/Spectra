#ifndef PYRAMID_H
#define PYRAMID_H

#include "../Utils/Headers.h"


class Pyramid
{
public:
	Pyramid();
	void setupPyramid();
	void updatePyramid();
	void deletePyramid();
private:
	GLuint VAO, VBO, EBO;
};

#endif