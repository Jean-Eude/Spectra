#include "Headers.h"
#include "tex.h"

#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF

Texture::Texture()
{

}


Texture::~Texture()
{
    glDeleteTextures(1, &this->texID);
}


void Texture::setTexture(const char* texPath, std::string texName, bool texFlip)
{
    this->texType = GL_TEXTURE_2D;

    std::string tempPath = std::string(texPath);

    if(texFlip)
        stbi_set_flip_vertically_on_load(true);
    else
        stbi_set_flip_vertically_on_load(false);

    glGenTextures(1, &this->texID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->texID);
    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &anisoFilterLevel);  // Request the maximum level of anisotropy the GPU used can support and use it
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, this->anisoFilterLevel);

    int width, height, numComponents;
    unsigned char* texData = stbi_load(tempPath.c_str(), &width, &height, &numComponents, 0);

    this->texWidth = width;
    this->texHeight = height;
    this->texComponents = numComponents;
    this->texName = texName;

    if (texData)
    {
        if (numComponents == 1)
            this->texFormat = GL_RED;
        else if (numComponents == 3)
            this->texFormat = GL_RGB;
        else if (numComponents == 4)
            this->texFormat = GL_RGBA;
        this->texInternalFormat = this->texFormat;

        glTexImage2D(GL_TEXTURE_2D, 0, this->texInternalFormat, this->texWidth, this->texHeight, 0, this->texFormat, GL_UNSIGNED_BYTE, texData);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);     // Need AF to get ride of the blur on textures
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glGenerateMipmap(GL_TEXTURE_2D);

        spdlog::info("Texture successfully loaded ! \n{}", texPath);
    }

    else
    {
        spdlog::error("Texture Failed Loading ! \n{}", texPath);
    }

    stbi_image_free(texData);

    glBindTexture(GL_TEXTURE_2D, 0);
}


void Texture::computeTexMipmap()
{
    glBindTexture(this->texType, this->texID);
    glGenerateMipmap(this->texType);
}


GLuint Texture::getTexID()
{
    return this->texID;
}


GLuint Texture::getTexWidth()
{
    return this->texWidth;
}


GLuint Texture::getTexHeight()
{
    return this->texHeight;
}


std::string Texture::getTexName()
{
    return this->texName;
}


void Texture::useTexture()
{
    glBindTexture(this->texType, this->texID);
}
