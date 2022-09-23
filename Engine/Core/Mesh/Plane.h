#ifndef PLANE_H
#define PLANE_H

#include "../Utils/Headers.h"

class Plane
{
public:
	Plane();
	void setupPlane(unsigned int X_SEGMENTS, unsigned int Y_SEGMENTS);
	void updatePlane();
	void deletePlane();
	void drawPolygons(GLenum mode);

private:
	GLuint VAO, VBO, EBO;

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> uv;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;
	std::vector<float> data;

	unsigned int indexCount;
	unsigned int stride;
	bool oddRow;
};

#endif