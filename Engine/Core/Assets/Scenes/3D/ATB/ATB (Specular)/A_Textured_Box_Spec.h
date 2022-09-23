#ifndef SCENE_H
#define SCENE_H

#include "../../../../../Utils/Headers.h"

#include "../../../../../Window/Window.h"
#include "../../../../../GUI/GUI.h"

#include "../../../../../Utils/Shader.h"
#include "../../../../../Utils/tex.h"

#include "../../../../../Mesh/Plane.h"
#include "../../../../../Mesh/Sphere.h"

#include "../../../../../Models/Mesh.h"
#include "../../../../../Models/Model.h"

#include "../../../../../Camera/Camera.h"

class Scene
{
	public:
		Scene();
		GLFWwindow* onInit();
		void onUpdate(GLFWwindow* window);
		void onEndUpdate(GLFWwindow* window);
		void onClose(GLFWwindow* window);

	private:
		int width = 1600, height = 900;
		const char* title = "A Textured Box (Specular)";
		const char* glsl = "#version 450";
		GLFWwindow* myWindow;


		Window Window;
		GUI Gui;

		Model Model;

		Plane Floor;
		Plane Wall_Back;
		Plane Wall_Left;

		Sphere LightSphere;

		Texture Diffuse;

		Shader BoxShader;
		Shader LightShader;

		Camera Camera;
};

#endif