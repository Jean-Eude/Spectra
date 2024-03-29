#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "Headers.h"

class Texture
{
    public:
        GLuint texID, texWidth, texHeight, texComponents;
        GLfloat anisoFilterLevel;
        GLenum texType, texInternalFormat, texFormat;
        std::string texName;

        Texture();
        ~Texture();
        void setTexture(const char* texPath, std::string texName, bool texFlip);
        void computeTexMipmap();
        GLuint getTexID();
        GLuint getTexWidth();
        GLuint getTexHeight();
        std::string getTexName();
        void useTexture();
};

#endif
