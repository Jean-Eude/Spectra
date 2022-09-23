#ifndef GUI_H
#define GUI_H

#include "../Utils/Headers.h"

class GUI 
{	
	public:
		GUI();
		void onSetupGUI(const char* glsl_version, GLFWwindow* window);
		void onCreateFrameGUI();
		void onRenderFrameGUI();
		void onCloseGUI();
};

#endif