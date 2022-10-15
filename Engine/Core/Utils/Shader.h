#ifndef _SHADER_H_
#define _SHADER_H_

#include "Headers.h"

class Shader
{
    public:
        GLuint Program;

        Shader();
        void setShader(const GLchar* vertexPath, const GLchar* fragmentPath);
        void useShader();
        void deleteShader();

        void setBindTexture(const GLchar* name, GLint v0);
        void setBindBool(const GLchar* name, GLboolean v0);
        void setBind1i(const GLchar* name, GLint v0);
        void setBind1f(const GLchar* name, GLfloat v0);
        void setBind2f(const GLchar* name, GLfloat v0, GLfloat v1);
        void setBind3f(const GLchar* name, GLfloat v0, GLfloat v1, GLfloat v2);
        void setBind3f(const GLchar* name, glm::vec3 variable);
        void setBind4f(const GLchar* name, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
        void setBind4fv(const GLchar* name, GLsizei count, GLboolean transpose, const GLfloat *value);
};

#endif
