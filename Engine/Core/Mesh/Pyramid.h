#ifndef _PYRAMID_H_
#define _PYRAMID_H_

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