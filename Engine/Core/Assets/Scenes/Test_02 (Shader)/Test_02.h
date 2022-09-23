#ifndef SCENE_H
#define SCENE_H

#include "../../../Utils/Headers.h"

#include "../../../Window/Window.h"
#include "../../../GUI/GUI.h"
#include "../../../Utils/Shader.h"
#include "../../../Mesh/Quad.h"


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
		const char* title = "SpectraEngine_Test02";
		const char* glsl = "#version 450";
		GLFWwindow* myWindow;

		Window Window;
		GUI GUI;
		Shader Shader;
		Quad Quad;
};

#endif