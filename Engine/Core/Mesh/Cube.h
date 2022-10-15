#ifndef _CUBE_H_
#define _CUBE_H_

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