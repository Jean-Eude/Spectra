#include "../../../../../Utils/Headers.h"

// Camera
double prevTime = glfwGetTime();
float FOVcamkey = 45.0f;
bool cameraMode = false;

glm::vec3 cameraPos   	= glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront 	= glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    	= glm::vec3(0.0f, 1.0f,  0.0f);

float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

float lastX =  800.0f; //width / 2.0f;
float lastY =  450.0; //height / 2.0f;
bool firstMouse = true;
float yaw   = -90.0f;   // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch =  0.0f;

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);


// Texture Properties

float tiletex = 0.4f;
float specStrength = 0.5f;
int shininess = 8;

// Floor Properties
glm::vec3 	translateFloor		= glm::vec3(-6.0f, 0.0f,  -10.0f);
glm::vec3 	scaleFloor			= glm::vec3(0.2f);
float 		angleFloor	 		= 90.0f;
glm::vec3 	axesFloor			= glm::vec3(1.0f, 0.0f, 0.0f); 


// Wall_Back Properties
glm::vec3 	translateWall_Back	= glm::vec3(-6.0f, -1.0f,  -11.0f);
glm::vec3 	scaleWall_Back		= glm::vec3(0.2f);
float 		angleWall_Back	 	= 90.0f;
glm::vec3 	axesWall_Back		= glm::vec3(1.0f, 0.0f, 0.0f); 

// Wall_Left Properties
glm::vec3 	translateWall_Left	= glm::vec3(5.0f, -1.0f,  0.0f);
glm::vec3 	scaleWall_Left		= glm::vec3(0.2f);
float 		angleWall_Left	 	= -90.0f;
glm::vec3 	axesWall_Left		= glm::vec3(0.0f, 1.0f, 0.0f); 
glm::vec3 	axesWall_Left1		= glm::vec3(0.0f, 0.0f, 1.0f);

// Sphere Properties
glm::vec3 	translateSphere		= glm::vec3(1.0f, 2.4f,  0.0f);
glm::vec3 	scaleSphere			= glm::vec3(0.2f);
float 		angleSphere	 		= 90.0f;
glm::vec3 	axesSphere			= glm::vec3(1.0f, 0.0f, 0.0f); 