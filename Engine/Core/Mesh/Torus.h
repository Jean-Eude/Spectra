#ifndef TORUS_H
#define TORUS_H

#include "../Utils/Headers.h"

class Torus
{
public:
	Torus();
	void setupTorus(unsigned int X_SEGMENTS, unsigned int Y_SEGMENTS, float u, float v, float a, float c);
	void updateTorus();
	void deleteTorus();

private:
	GLuint VAO, VBO, EBO;

	std::vector<glm::vec3> positions;
    std::vector<glm::vec2> uv;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;

    unsigned int indexCount;
	std::vector<float> data;
	unsigned int stride;
	bool oddRow;

	const float PI = 3.14159265359f;
};

#endif