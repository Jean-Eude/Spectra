#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Utils/Headers.h"


class Triangle
{
public:
	Triangle();
	void setupTriangle();
	void updateTriangle();
	void deleteTriangle();
private:
	GLuint VAO, VBO, EBO;
};


#endif