#include "../../../Utils/Headers.h"

GLfloat color[4];


// Camera
float rotation = 90.0f;
glm::vec3 axesRotate = glm::vec3(1.0f, 0.0f, 0.0f); 
double prevTime = glfwGetTime();
float FOVcamkey = 45.0f;
bool cameraMode = false;

glm::vec3 cameraPos   	= glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront 	= glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    	= glm::vec3(0.0f, 1.0f,  0.0f);
glm::vec3 translatePos	= glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 scale			= glm::vec3(0.2f);

float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

float lastX =  800.0f; //width / 2.0f;
float lastY =  450.0; //height / 2.0f;
bool firstMouse = true;
float yaw   = -90.0f;   // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch =  0.0f;

