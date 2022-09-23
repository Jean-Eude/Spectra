#ifndef SCENE_H
#define SCENE_H

#include "../../../Utils/Headers.h"

#include "../../../Window/Window.h"
#include "../../../GUI/GUI.h"
#include "../../../Utils/Shader.h"
#include "../../../Mesh/Triangle.h"
#include "../../../Mesh/Quad.h"
#include "../../../Mesh/Cube.h"
#include "../../../Utils/tex.h"
#include "../../../Camera/Matrix.h"
#include "../../../Models/Mesh.h"
#include "../../../Models/Model.h"
#include "../../../Camera/Camera.h"

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
		const char* title = "SpectraEngine_Test15 (Maps)";
		const char* glsl = "#version 450";
		GLFWwindow* myWindow;


		Window Window;
		GUI Gui;
		Triangle Triangle;
		Quad Quad;
		Matrix Matrix;
		Model Model;
		Camera Camera;

		Cube lightCube;
		Cube Cube;

		Texture TextureBase;
		Texture TextureSpec;

		Shader lightingShader;
		Shader lightCubeShader;
};

#endif