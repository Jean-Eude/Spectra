#ifndef _QUAD_H_
#define _QUAD_H_

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