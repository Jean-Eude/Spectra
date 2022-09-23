#ifndef SCENE_H
#define SCENE_H

#include "../../../../Utils/Headers.h"

#include "../../../../Window/Window.h"
#include "../../../../Input/Input.h"
#include "../../../../GUI/GUI.h"
#include "../../../../Utils/Shader.h"
#include "../../../../Mesh/Quad2D.h"
#include "../../../../Utils/tex.h"

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
	const char* title = "Image Processing";
	const char* glsl = "#version 450";
	GLFWwindow* myWindow;

	Window Window;
	Input Input;
	GUI Gui;
	Quad2D Quad2D;
	Texture Texture;

	Shader ShaderBase;
	Shader ShaderGr;
	Shader ShaderTrh;
	Shader ShaderIVC;
	Shader ShaderGamCorr;
	Shader ShaderBRG;
	Shader ShaderCont;
	Shader ShaderPxl;
	Shader ShaderSl;

	Shader ShaderRidge;
	Shader ShaderSharpen;
	Shader ShaderSobel;
	Shader ShaderRobC;
	Shader ShaderLap;
	Shader ShaderEmboss;
	Shader ShaderGaussian;

	Shader ShaderBumpTest;
	Shader ShaderDiff2Height;
	Shader ShaderDiff2Normal;
	Shader ShaderMethodsHeights;
};

#endif