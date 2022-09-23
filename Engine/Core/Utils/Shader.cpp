#include "Headers.h"

#include "Shader.h"
#include "Texture.h"


Shader::Shader()
{

}

void Shader::setShader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
    // Shaders reading
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);

    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();

        spdlog::info("Shaders successfully loaded !");
    }

    catch (std::ifstream::failure e)
    {
        spdlog::error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ", 1);
    }

    const GLchar* vShaderCode = vertexCode.c_str();
    const GLchar * fShaderCode = fragmentCode.c_str();

    // Shaders compilation
    GLuint vertex, fragment;
    GLint success;
    GLchar infoLog[512];

    // Vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        spdlog::error("ERROR::SHADER::VERTEX::COMPILATION_FAILED \n{}", vertexPath);
    }
    else
    {
        spdlog::info("SHADER::VERTEX::COMPILATION_COMPLETED \n{}", vertexPath);
    }

    // Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        spdlog::error("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED \n{}", fragmentPath);
    }
    else
    {
        spdlog::info("SHADER::FRAGMENT::COMPILATION_COMPLETED \n{}", fragmentPath);
    }

    // Shader Program
    this->Program = glCreateProgram();
    glAttachShader(this->Program, vertex);
    glAttachShader(this->Program, fragment);
    glLinkProgram(this->Program);
    glGetProgramiv(this->Program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
        spdlog::error("ERROR::SHADER::PROGRAM::LINKING_FAILED", 1);
    }
    else
    {
        spdlog::info("SHADER::PROGRAM::LINKING_COMPLETED");
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


void Shader::useShader()
{
    glUseProgram(this->Program);
}

void Shader::deleteShader()
{
    glDeleteProgram(this->Program);
}

void Shader::setBindTexture(const GLchar* name, GLint v0)
{
    glUniform1i(glGetUniformLocation(this->Program, name), v0);
}

void Shader::setBind1f(const GLchar* name, GLfloat v0)
{
    glUniform1f(glGetUniformLocation(this->Program, name), v0);
}

void Shader::setBind1i(const GLchar* name, GLint v0)
{
    glUniform1i(glGetUniformLocation(this->Program, name), v0);
}

void Shader::setBind2f(const GLchar* name, GLfloat v0, GLfloat v1)
{
    glUniform2f(glGetUniformLocation(this->Program, name), v0, v1);
}

void Shader::setBind3f(const GLchar* name, GLfloat v0, GLfloat v1, GLfloat v2)
{
    glUniform3f(glGetUniformLocation(this->Program, name), v0, v1, v2);
}

void Shader::setBind3f(const GLchar* name, glm::vec3 variable)
{
    glUniform3f(glGetUniformLocation(this->Program, name), variable.r, variable.g, variable.b);
}

void Shader::setBindBool(const GLchar* name, GLboolean v0)
{
    glUniform1i(glGetUniformLocation(this->Program, name), v0);
}

void Shader::setBind4f(const GLchar* name,GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    glUniform4f(glGetUniformLocation(this->Program, name), r, g, b, a);
}

void Shader::setBind4fv(const GLchar* name, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    glUniformMatrix4fv(glGetUniformLocation(this->Program, name), count, transpose, value);
}
