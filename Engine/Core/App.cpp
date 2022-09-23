#include "Headers.h"
#include "Assets/Scenes/3D/ATB/ATB (Blinn_Phong)/A_Textured_Box_BP.h"


int main(int argc, char* argv[])
{
    Scene Scene;
    GLFWwindow* myWindow = Scene.onInit();

    while (!glfwWindowShouldClose(myWindow))
    {    
        Scene.onUpdate(myWindow);
		Scene.onEndUpdate(myWindow);
    }

    Scene.onClose(myWindow);
    return 0;
}




