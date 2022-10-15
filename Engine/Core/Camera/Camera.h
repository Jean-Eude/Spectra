#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../Utils/Headers.h"
#include "../Utils/Shader.h"

class Camera
{
	public:
		Camera();
		void Setup(int width, int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, bool translate, bool scale, bool rotate, glm::vec3 translatePos, glm::vec3 Scale, glm::vec3 Rotation, float angleRotation, float FOV, Shader myShader);

	private:
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 proj;
};
#endif