#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "../Utils/Headers.h"

class Sphere
{
public:
	Sphere();
	void setupSphere(unsigned int X_SEGMENTS, unsigned int Y_SEGMENTS);
	void updateSphere();
	void deleteSphere();

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