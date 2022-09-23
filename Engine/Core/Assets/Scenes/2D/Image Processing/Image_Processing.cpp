#include "Headers.h"
#include "Image_Processing.h"
#include "VarH.h"


Scene::Scene()
{

}



GLFWwindow* Scene::onInit()
{
    Window.setupOpenGL(4, 5);
    myWindow = Window.initWindow(width, height, title);
    Window.logWindow(myWindow);
    Window.addWindow(myWindow, width, height);

    // ------------------------ //

    ShaderBase.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/base.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/base.frag");
    ShaderGr.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/grayscale.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/grayscale.frag");
    ShaderTrh.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/treshold.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/treshold.frag");
    ShaderIVC.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/invertcol.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/invertcol.frag");
    ShaderGamCorr.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/gamma.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/gamma.frag");
    ShaderBRG.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/brightness.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/brightness.frag");
    ShaderCont.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/contrast.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/contrast.frag");
    ShaderPxl.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/pixellation.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/pixellation.frag");
    ShaderSl.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/solarize.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/solarize.frag");


    ShaderRidge.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/ridge.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/ridge.frag");
    ShaderSharpen.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/sharpen.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/sharpen.frag");
    ShaderSobel.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/sobel.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/sobel.frag");
    ShaderRobC.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/robert_cross.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/robert_cross.frag");
    ShaderLap.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/laplace.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/laplace.frag");
    ShaderEmboss.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/emboss.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/emboss.frag");
    ShaderGaussian.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/gaussianblur.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/gaussianblur.frag");

    ShaderBumpTest.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/normalt.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/normalt.frag");
    ShaderDiff2Height.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/heightmap.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/heightmap.frag");
    ShaderDiff2Normal.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/normalmap.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/normalmap.frag");
    ShaderMethodsHeights.setShader("Source/Assets/Scenes/2D/Image Processing/Shaders/heights.vert", "Source/Assets/Scenes/2D/Image Processing/Shaders/heights.frag");


    ShaderTrh.setBind1f("treshold", treshold);
    ShaderGamCorr.setBind1f("gamma", gamma);
    ShaderBRG.setBind1f("brightness", brightness);
    ShaderCont.setBind1f("contrast", contrast);

    ShaderPxl.setBind1f("pixelSize", pixelSize);
    ShaderPxl.setBind2f("uResolution", width, height);

    ShaderSl.setBind2f("uResolution", width, height);
    ShaderSl.setBind3f("tresholdSolarize", tresholdSolarize[0], tresholdSolarize[1], tresholdSolarize[2]);
    ShaderSl.setBindBool("enableSabbEff", enableSabbEff);

    ShaderRidge.setBindBool("grayscaledRidge", grayscaledRidge);
    ShaderRidge.setBindBool("invertRidge", invertRidge);
    ShaderRidge.setBindBool("tresholdRidge", tresholdRidge);
    ShaderRidge.setBind1f("tresholdScaleRidge", tresholdScaleRidge);

    ShaderSobel.setBindBool("grayscaledSobel", grayscaledSobel);
    ShaderSobel.setBindBool("invertSobel", invertSobel);
    ShaderSobel.setBindBool("tresholdSobel", tresholdSobel);
    ShaderSobel.setBind1f("tresholdScaleSobel", tresholdScaleSobel);

    ShaderRobC.setBindBool("grayscaledRobC", grayscaledRobC);
    ShaderRobC.setBindBool("invertRobC", invertRobC);
    ShaderRobC.setBindBool("tresholdRobC", tresholdRobC);
    ShaderRobC.setBind1f("tresholdScaleRobC", tresholdScaleRobC);

    ShaderLap.setBindBool("grayscaledLap", grayscaledLap);
    ShaderLap.setBindBool("invertLap", invertLap);
    ShaderLap.setBindBool("tresholdLap", tresholdLap);
    ShaderLap.setBind1f("tresholdScaleLap", tresholdScaleLap);

    ShaderEmboss.setBindBool("grayscaledEmb", grayscaledEmb);
    ShaderEmboss.setBindBool("invertEmb", invertEmb);
    ShaderEmboss.setBindBool("tresholdEmb", tresholdEmb);
    ShaderEmboss.setBind1f("tresholdScaleEmb", tresholdScaleEmb);
    ShaderEmboss.setBindBool("pass1", pass1);
    ShaderEmboss.setBindBool("pass2", pass2);
    ShaderEmboss.setBindBool("pass3", pass3);
    ShaderEmboss.setBindBool("pass4", pass4);
    ShaderEmboss.setBindBool("Dpass1", Dpass1);
    ShaderEmboss.setBindBool("Dpass2", Dpass2);
    ShaderEmboss.setBindBool("Epass1", Epass1);

    ShaderGaussian.setBind2f("uResolution", width, height);
    ShaderGaussian.setBind1i("phase", phase);
    ShaderGaussian.setBind1i("radius", radius);
    ShaderGaussian.setBind1f("sigma", sigma);

    ShaderDiff2Height.setBind1f("brightness", brightness2Height);
    ShaderDiff2Height.setBind1f("contrast", contrast2Height);
    ShaderDiff2Height.setBind1f("gamma", gamma2Height);
    ShaderDiff2Height.setBind1f("minLevel", minLevel2Height);
    ShaderDiff2Height.setBind1f("maxLevel", maxLevel2Height);

    ShaderMethodsHeights.setBindBool("red", redHeight);
    ShaderMethodsHeights.setBindBool("green", greenHeight);
    ShaderMethodsHeights.setBindBool("blue", blueHeight);
    ShaderMethodsHeights.setBindBool("alphab", alphaHeight);
    ShaderMethodsHeights.setBindBool("maxc", maxHeight);
    ShaderMethodsHeights.setBindBool("screenblend", screenB);
    ShaderMethodsHeights.setBindBool("invert", invertHeight);
    ShaderMethodsHeights.setBindBool("emboss", embossHeight);


    // ----------------------- //

    Texture.setTexture("Source/Assets/Scenes/2D/Image Processing/Textures/brick.png", "imgtex", true);
    ShaderBase.setBindTexture("tex", 0);  // Pas obligatoire !
    ShaderGr.setBindTexture("tex", 0);  // Pas obligatoire !
    ShaderTrh.setBindTexture("tex", 0);  // Pas obligatoire !
    ShaderIVC.setBindTexture("tex", 0);  // Pas obligatoire !
    ShaderGamCorr.setBindTexture("tex", 0);// Pas obligatoire !
    ShaderBRG.setBindTexture("tex", 0);// Pas obligatoire !
    ShaderCont.setBindTexture("tex", 0);// Pas obligatoire !
    ShaderPxl.setBindTexture("tex", 0);// Pas obligatoire !
    ShaderSl.setBindTexture("tex", 0);// Pas obligatoire !

    ShaderRidge.setBindTexture("tex", 0);
    ShaderSharpen.setBindTexture("tex", 0);
    ShaderSobel.setBindTexture("tex", 0);
    ShaderRobC.setBindTexture("tex", 0);
    ShaderLap.setBindTexture("tex", 0);
    ShaderEmboss.setBindTexture("tex", 0);
    ShaderGaussian.setBindTexture("tex", 0);

    ShaderBumpTest.setBindTexture("tex", 0);
    ShaderDiff2Height.setBindTexture("tex", 0);
    ShaderDiff2Normal.setBindTexture("tex", 0);
    ShaderMethodsHeights.setBindTexture("tex", 0);

    Quad2D.setupQuad2D();
    Gui.onSetupGUI("#version 450", myWindow);

    return myWindow;
}



void Scene::onUpdate(GLFWwindow* window)
{
    Input.closeWindowInput(window);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Texture.useTexture();
    Gui.onCreateFrameGUI();


    ShaderBase.useShader();
    if (drawGrayscale == true)
    {
        ShaderGr.useShader();
    } 
    if (drawTreshold == true)
    {
        ShaderTrh.useShader();
    }
    if (drawIVC == true)
    {
        ShaderIVC.useShader();
    }
    if (drawGammaCorrection == true)
    {
        ShaderGamCorr.useShader();
    }
    if (drawBrightness == true)
    {
        ShaderBRG.useShader();
    }
    if (drawContrast== true)
    {
        ShaderCont.useShader();
    }
    if (drawPixellation == true)
    {
        ShaderPxl.useShader();
    }
    if (drawSolarize == true)
    {
        ShaderSl.useShader();
    }

    if (drawRidge == true)
    {
        ShaderRidge.useShader();
    }
    if (drawSharpen == true)
    {
        ShaderSharpen.useShader();
    }
    if (drawSobel == true)
    {
        ShaderSobel.useShader();
    }
    if (drawRobC == true)
    {
        ShaderRobC.useShader();
    }
    if (drawLap == true)
    {
        ShaderLap.useShader();
    }
    if (drawEmb == true)
    {
        ShaderEmboss.useShader();
    }
    if (drawGaussianB == true)
    {
        ShaderGaussian.useShader();
    }

    if (drawBumpt == true)
    {
        ShaderBumpTest.useShader();
    }
    if (drawDiff2Height == true)
    {
        ShaderDiff2Height.useShader();
    }
    if (drawDiff2Normal == true)
    {
        ShaderDiff2Normal.useShader();
    }
    if (drawMethodsHeights == true)
    {
        ShaderMethodsHeights.useShader();
    }


    Quad2D.updateQuad2D();


    ImGui::Begin("Image Processing");

    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Effects"))
    {
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Base"))
        {
            drawBase = true;

            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;

        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Grayscale"))
        {
            drawGrayscale = true;

            drawBase = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;

        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Tresholding"))
        {
            drawTreshold = true;

            drawBase = false;
            drawGrayscale = true;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Normal = false;
            drawDiff2Height = false;
            drawMethodsHeights = false;

            ImGui::SliderFloat("Treshold", &treshold, 0.0f, 1.0f);

            ShaderTrh.useShader();
            ShaderTrh.setBind1f("treshold", treshold);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Invert colors"))
        {
            drawIVC = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;

        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Gamma Correction"))
        {
            drawGammaCorrection = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            ImGui::SliderFloat("Gamma", &gamma, 0.0f, 10.0f);

            ShaderGamCorr.useShader();
            ShaderGamCorr.setBind1f("gamma", gamma);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Brightness Correction"))
        {
            drawBrightness = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            ImGui::SliderFloat("Brightness", &brightness, 0.0f, 1.0f);

            ShaderBRG.useShader();
            ShaderBRG.setBind1f("brightness", brightness);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Contrast Correction"))
        {
            drawContrast = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            ImGui::SliderFloat("Contrast", &contrast, 0.0f, 10.0f);

            ShaderCont.useShader();
            ShaderCont.setBind1f("contrast", contrast);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Pixellation"))
        {
            drawPixellation = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            ImGui::SliderFloat("Pixel", &pixelSize, 0.0f, 30.0f);

            ShaderPxl.useShader();
            ShaderPxl.setBind1f("pixelSize", pixelSize);
            ShaderPxl.setBind2f("uResolution", width, height);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Solarize / Sabbatier Effect"))
        {
            drawSolarize = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            ImGui::Spacing();
            ImGui::ColorEdit3("Treshold Levels", tresholdSolarize);
            ImGui::Spacing();
            ImGui::Text("Sabbatier Effect");
            ImGui::Spacing();
            ImGui::Checkbox("Sabbatier", &enableSabbEff);


            ShaderSl.useShader();
            ShaderSl.setBind2f("uResolution", width, height);
            ShaderSl.setBind3f("tresholdSolarize", tresholdSolarize[0], tresholdSolarize[1], tresholdSolarize[2]);
            ShaderSl.setBindBool("enableSabbEff", enableSabbEff);
        }
    }
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Filters")) 
    {
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Ridge Detection"))
        {
            drawRidge = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            if (ImGui::Checkbox("Grayscaled", &grayscaledRidge))
            {
                invertRidge = false;
                tresholdRidge = false;
            }

            if (ImGui::Checkbox("Invert", &invertRidge))
            {
                grayscaledRidge = false;
                tresholdRidge = false;
            }

            if (ImGui::Checkbox("Treshold", &tresholdRidge))
            {
                invertRidge = false;
                grayscaledRidge = false;
            }

            ShaderRidge.useShader();
            
            ImGui::SliderFloat("Treshold_Ridge", &tresholdScaleRidge, 0.0f, 1.0f);
            
            ShaderRidge.setBind1f("tresholdScaleRidge", tresholdScaleRidge);
            ShaderRidge.setBindBool("grayscaledRidge", grayscaledRidge);
            ShaderRidge.setBindBool("invertRidge", invertRidge);
            ShaderRidge.setBindBool("tresholdRidge", tresholdRidge);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Sharpen"))
        {
            drawSharpen = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;

        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Sobel Filter"))
        {
            drawSobel = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;

            
            if (ImGui::Checkbox("Grayscaled", &grayscaledSobel))
            {
                invertSobel = false;
                tresholdSobel = false;
            }

            if (ImGui::Checkbox("Invert", &invertSobel))
            {
                grayscaledSobel = false;
                tresholdSobel = false;
            }

            if (ImGui::Checkbox("Treshold", &tresholdSobel))
            {
                invertSobel = false;
                grayscaledSobel = false;
            }

            ShaderSobel.useShader();

            ImGui::SliderFloat("Treshold_Sobel", &tresholdScaleSobel, 0.0f, 1.0f);

            ShaderSobel.setBind1f("tresholdScaleSobel", tresholdScaleSobel);
            ShaderSobel.setBindBool("grayscaledSobel", grayscaledSobel);
            ShaderSobel.setBindBool("invertSobel", invertSobel);
            ShaderSobel.setBindBool("tresholdSobel", tresholdSobel);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Robert Cross Filter"))
        {
            drawRobC = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            if (ImGui::Checkbox("Grayscaled", &grayscaledRobC))
            {
                invertRobC = false;
                tresholdRobC = false;
            }

            if (ImGui::Checkbox("Invert", &invertRobC))
            {
                grayscaledRobC = false;
                tresholdRobC = false;
            }

            if (ImGui::Checkbox("Treshold", &tresholdRobC))
            {
                invertRobC = false;
                grayscaledRobC = false;
            }

            ShaderRobC.useShader();

            ImGui::SliderFloat("Treshold_Robert_Cross", &tresholdScaleRobC, 0.0f, 1.0f);

            ShaderRobC.setBind1f("tresholdScaleRobC", tresholdScaleRobC);
            ShaderRobC.setBindBool("grayscaledRobC", grayscaledRobC);
            ShaderRobC.setBindBool("invertRobC", invertRobC);
            ShaderRobC.setBindBool("tresholdRobC", tresholdRobC);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Discrete Laplace Filter"))
        {
            drawLap = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;



            if (ImGui::Checkbox("Grayscaled", &grayscaledLap))
            {
                invertLap = false;
                tresholdLap = false;
            }

            if (ImGui::Checkbox("Invert", &invertLap))
            {
                grayscaledLap = false;
                tresholdLap = false;
            }

            if (ImGui::Checkbox("Treshold", &tresholdLap))
            {
                invertLap = false;
                grayscaledLap = false;
            }

            ShaderLap.useShader();

            ImGui::SliderFloat("Treshold_Laplace", &tresholdScaleLap, 0.0f, 1.0f);

            ShaderLap.setBind1f("tresholdScaleLap", tresholdScaleLap);
            ShaderLap.setBindBool("grayscaledLap", grayscaledLap);
            ShaderLap.setBindBool("invertLap", invertLap);
            ShaderLap.setBindBool("tresholdLap", tresholdLap);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Emboss Filter"))
        {
            drawEmb = true;

            drawBase = false;
            drawGrayscale = false;
            drawTreshold = false;
            drawIVC = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;



            if (ImGui::Checkbox("Grayscaled", &grayscaledEmb))
            {
                invertEmb = false;
                tresholdEmb = false;
            }

            if (ImGui::Checkbox("Invert", &invertEmb))
            {
                grayscaledEmb = false;
                tresholdEmb = false;
            }

            if (ImGui::Checkbox("Treshold", &tresholdEmb))
            {
                invertEmb = false;
                grayscaledEmb = false;
            }

 

            ImGui::Spacing();
            ImGui::SliderFloat("Treshold_Emboss", &tresholdScaleEmb, 0.0f, 1.0f);
            ImGui::Spacing();
            ImGui::Text("Basic Kernels");
            ImGui::Spacing();
            ImGui::Spacing();

            if(ImGui::Checkbox("1", &pass1))
            {
                pass2 = false;
                pass3 = false;
                pass4 = false;
                Dpass1 = false;
                Dpass2 = false;
                Epass1 = false;
            }
            ImGui::SameLine();
            if(ImGui::Checkbox("2", &pass2))
            {
                pass1 = false;
                pass3 = false;
                pass4 = false;
                Dpass1 = false;
                Dpass2 = false;
                Epass1 = false;
            }
            ImGui::SameLine();
            if (ImGui::Checkbox("3", &pass3))
            {
                pass1 = false;
                pass2 = false;
                pass4 = false;
                Dpass1 = false;
                Dpass2 = false;
                Epass1 = false;
            }
            ImGui::SameLine();
            if (ImGui::Checkbox("4", &pass4))
            {
                pass1 = false;
                pass2 = false;
                pass3 = false;
                Dpass1 = false;
                Dpass2 = false;
                Epass1 = false;
            }
            ImGui::Spacing();
            ImGui::Text("Rotation Kernels");
            ImGui::Spacing();
            ImGui::Spacing();
            if (ImGui::Checkbox("D1", &Dpass1))
            {
                pass1 = false;
                pass2 = false;
                pass3 = false;
                pass4 = false;
                Dpass2 = false;
                Epass1 = false;
            }
            ImGui::SameLine();
            if (ImGui::Checkbox("D2", &Dpass2))
            {
                pass1 = false;
                pass2 = false;
                pass3 = false;
                pass4 = false;
                Dpass1 = false;
                Epass1 = false;
            }
            ImGui::Spacing();
            ImGui::Text("Edges Kernel");
            ImGui::Spacing();
            ImGui::Spacing();
            if (ImGui::Checkbox("E1", &Epass1))
            {
                pass1 = false;
                pass2 = false;
                pass3 = false;
                pass4 = false;
                Dpass1 = false;
                Dpass2 = false;
            }

            ShaderEmboss.useShader();

            ShaderEmboss.setBind1f("tresholdScaleEmb", tresholdScaleEmb);
            ShaderEmboss.setBindBool("grayscaledEmb", grayscaledEmb);
            ShaderEmboss.setBindBool("invertEmb", invertEmb);
            ShaderEmboss.setBindBool("tresholdEmb", tresholdEmb);

            ShaderEmboss.setBindBool("pass1", pass1);
            ShaderEmboss.setBindBool("pass2", pass2);
            ShaderEmboss.setBindBool("pass3", pass3);
            ShaderEmboss.setBindBool("pass4", pass4);
            ShaderEmboss.setBindBool("Dpass1", Dpass1);
            ShaderEmboss.setBindBool("Dpass2", Dpass2);
            ShaderEmboss.setBindBool("Epass1", Epass1);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Gaussian Blur"))
        {
            drawGaussianB = true;

            drawBase = false;
            drawGrayscale = false;
            drawIVC = false;
            drawTreshold = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;



            ImGui::SliderInt("Phase", &phase, 0, 2);
            ImGui::SliderInt("Radius", &radius, 0, 20);
            ImGui::SliderFloat("Sigma", &sigma, 0.0f, 10.0f);

            ShaderGaussian.useShader();
            ShaderGaussian.setBind1i("phase", phase);
            ShaderGaussian.setBind1i("radius", radius);
            ShaderGaussian.setBind1f("sigma", sigma);
            ShaderGaussian.setBind2f("uResolution", width, height);
        }
    }
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Textures Mapping"))
    {
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Diffuse Map    -->     Bump Map"))
        {
            drawBumpt = true;

            drawBase = false;
            drawGrayscale = false;
            drawIVC = false;
            drawTreshold = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawDiff2Height = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;

        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Diffuse Map    -->     Grayscale/Height Map"))
        {
            drawDiff2Height = true;

            drawBase = false;
            drawGrayscale = false;
            drawIVC = false;
            drawTreshold = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Normal = false;
            drawMethodsHeights = false;


            ImGui::SliderFloat("Brightness", &brightness2Height, -2.0f, 2.0f);
            ImGui::SliderFloat("Contrast", &contrast2Height, -5.0f, 5.0f);
            ImGui::SliderFloat("Gamma", &gamma2Height, -3.0f, 3.0f);
            ImGui::SliderFloat("Min Level", &minLevel2Height, -1.0f, 1.0f);
            ImGui::SliderFloat("Max level", &maxLevel2Height, -2.0f, 2.0f);
            
            ShaderDiff2Height.useShader();
            ShaderDiff2Height.setBind1f("brightness", brightness2Height);
            ShaderDiff2Height.setBind1f("contrast", contrast2Height);
            ShaderDiff2Height.setBind1f("gamma", gamma2Height);
            ShaderDiff2Height.setBind1f("minLevel", minLevel2Height);
            ShaderDiff2Height.setBind1f("maxLevel", maxLevel2Height);
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Diffuse Map    -->     Normal Map"))
        {
            drawDiff2Normal = true;

            drawBase = false;
            drawGrayscale = false;
            drawIVC = false;
            drawTreshold = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawMethodsHeights = false;
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Diffuse Map    -->     Height Map"))
        {
            drawMethodsHeights = true;

            drawBase = false;
            drawGrayscale = false;
            drawIVC = false;
            drawTreshold = false;
            drawGammaCorrection = false;
            drawBrightness = false;
            drawContrast = false;
            drawPixellation = false;
            drawSolarize = false;
            drawRidge = false;
            drawSharpen = false;
            drawSobel = false;
            drawRobC = false;
            drawLap = false;
            drawEmb = false;
            drawGaussianB = false;
            drawBumpt = false;
            drawDiff2Height = false;
            drawDiff2Normal = true;

            ImGui::Spacing();
            ImGui::Text("Choice the channels RGBA for the heightmap");
            ImGui::Spacing();
            if (ImGui::Checkbox("Red Channel", &redHeight))
            {
                greenHeight = false;
                blueHeight = false;
                alphaHeight = false;
                maxHeight = false;
                screenB = false;
            }
            if (ImGui::Checkbox("Green Channel", &greenHeight))
            {
                redHeight = false;
                blueHeight = false;
                alphaHeight = false;
                maxHeight = false;
            }
            if (ImGui::Checkbox("Blue Channel", &blueHeight))
            {
                redHeight = false;
                greenHeight = false;
                alphaHeight = false;
                maxHeight = false;
                screenB = false;
            }
            if (ImGui::Checkbox("Alpha Channel", &alphaHeight))
            {
                redHeight = false;      
                greenHeight = false;
                blueHeight = false;
                maxHeight = false;
                screenB = false;
            }
            ImGui::Spacing();
            ImGui::Text("Max of the 3 three channels");
            ImGui::Spacing();
            if (ImGui::Checkbox("Max Channel", &maxHeight))
            {
                redHeight = false;
                greenHeight = false;
                blueHeight = false;
                alphaHeight = false;
                screenB = false;
            }
            ImGui::Spacing();
            ImGui::Text("Screen Blending");
            ImGui::Spacing();
            if (ImGui::Checkbox("Screen Blend", &screenB))
            {
                redHeight = false;
                greenHeight = false;
                blueHeight = false;
                alphaHeight = false;
                maxHeight = false;
            }
            ImGui::Spacing();
            ImGui::Text("Invert the Height Map channels");
            ImGui::Spacing();
            ImGui::Checkbox("Invert Height Map", &invertHeight);
            ImGui::Spacing();
            ImGui::Text("Activate Emboss Edges Filter");
            ImGui::Spacing();
            ImGui::Checkbox("Emboss Filter", &embossHeight);


            ShaderMethodsHeights.useShader();
            ShaderMethodsHeights.setBindBool("red", redHeight);
            ShaderMethodsHeights.setBindBool("green", greenHeight);
            ShaderMethodsHeights.setBindBool("blue", blueHeight);
            ShaderMethodsHeights.setBindBool("alphab", alphaHeight);
            ShaderMethodsHeights.setBindBool("maxc", maxHeight);
            ShaderMethodsHeights.setBindBool("screenblend", screenB);
            ShaderMethodsHeights.setBindBool("invert", invertHeight);
            ShaderMethodsHeights.setBindBool("emboss", embossHeight);
        }
    }

    ImGui::End();
    Gui.onRenderFrameGUI(); 
}



void Scene::onEndUpdate(GLFWwindow* window)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}



void Scene::onClose(GLFWwindow* window)
{
    Gui.onCloseGUI();
    Quad2D.deleteQuad2D();

    ShaderBase.deleteShader();
    ShaderGr.deleteShader();
    ShaderTrh.deleteShader();
    ShaderIVC.deleteShader();
    ShaderGamCorr.deleteShader();
    ShaderBRG.deleteShader();
    ShaderCont.deleteShader();
    ShaderPxl.deleteShader();
    ShaderSl.deleteShader();
    ShaderRidge.deleteShader();
    ShaderSharpen.deleteShader();
    ShaderSobel.deleteShader();
    ShaderRobC.deleteShader();
    ShaderLap.deleteShader();
    ShaderEmboss.deleteShader();
    ShaderGaussian.deleteShader();
    ShaderBumpTest.deleteShader();
    ShaderDiff2Height.deleteShader();
    ShaderDiff2Normal.deleteShader();

    Window.cleanWindow(window);
}