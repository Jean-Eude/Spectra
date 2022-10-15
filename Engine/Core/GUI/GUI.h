#ifndef _GUI_H_
#define _GUI_H_

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