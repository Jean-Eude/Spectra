#include "../../../../Utils/Headers.h"


bool drawBase = true;

bool drawGrayscale = false;

bool drawTreshold = false;
float treshold = 0.5f;

bool drawIVC = false;

bool drawGammaCorrection = false;
GLfloat gamma = 2.2f;

bool drawBrightness = false;
float brightness = 0.5f;

bool drawContrast = false;
float contrast = 2.0f;

bool drawPixellation = false;
float pixelSize = 2.0f;

bool drawSolarize = false;
GLfloat tresholdSolarize[3] = { 1.0f, 0.92f, 0.1f };
bool enableSabbEff = false;

bool drawRidge = false;
bool grayscaledRidge = false;
bool invertRidge = false;
bool tresholdRidge = false;
float tresholdScaleRidge = 0.5f;

bool drawSharpen = false;

bool drawSobel = false;
bool grayscaledSobel = false;
bool invertSobel = false;
bool tresholdSobel = false;
float tresholdScaleSobel = 0.5f;

bool drawRobC = false;
bool grayscaledRobC = false;
bool invertRobC = false;
bool tresholdRobC = false;
float tresholdScaleRobC = 0.5f;

bool drawLap = false;
bool grayscaledLap = false;
bool invertLap = false;
bool tresholdLap = false;
float tresholdScaleLap = 0.5f;

bool drawEmb = false;
bool grayscaledEmb = false;
bool invertEmb = false;
bool tresholdEmb = false;
float tresholdScaleEmb = 0.5f;
bool pass1 = true;
bool pass2 = false;
bool pass3 = false;
bool pass4 = false;
bool Dpass1 = false;
bool Dpass2 = false;
bool Epass1 = false;

bool drawGaussianB = false; 
int phase = 1;
int radius = 10;
float sigma = 3.0f;

bool drawBumpt = false;

bool drawDiff2Normal = false;

bool drawDiff2Height = false;
float contrast2Height = 1.0f;
float brightness2Height = 0.0f;
float gamma2Height = 2.2f;
float minLevel2Height = 0.0f;
float maxLevel2Height = 1.0f;

bool drawMethodsHeights = false;
bool redHeight = false;
bool greenHeight = false;
bool blueHeight = false;
bool alphaHeight = false;
bool maxHeight = false;
bool screenB = false;
bool invertHeight = false;
bool embossHeight = false;