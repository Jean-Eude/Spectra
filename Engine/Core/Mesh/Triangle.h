#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

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