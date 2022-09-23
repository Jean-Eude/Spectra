#ifndef CUBE_H
#define CUBE_H

#include "../Utils/Headers.h"


class Cube
{
public:
	Cube();
	void setupCube();
	void updateCube();
	void deleteCube();
private:
	GLuint VAO, VBO, EBO;
};

#endif