#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "../Utils/Headers.h"
#include "../Utils/Shader.h"

class Matrix
{
	public:
		Matrix();
		void PPMatrix(float rotation, int width, int height, float FOV, Shader myShader);
};

#endif