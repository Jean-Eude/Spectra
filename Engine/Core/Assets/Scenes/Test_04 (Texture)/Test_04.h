#ifndef SCENE_H
#define SCENE_H

#include "../../../Utils/Headers.h"

#include "../../../Window/Window.h"
#include "../../../GUI/GUI.h"
#include "../../../Utils/Shader.h"
#include "../../../Mesh/Triangle.h"
#include "../../../Mesh/Quad.h"
#include "../../../Utils/tex.h"


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
		const char* title = "SpectraEngine_Test04 (Texture)";
		const char* glsl = "#version 450";
		GLFWwindow* myWindow;


		Window Window;
		GUI Gui;
		Shader Shader;
		Triangle Triangle;
		Quad Quad;
		Texture Texture;
};

#endif