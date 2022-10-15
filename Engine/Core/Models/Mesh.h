#ifndef _MESH_H_
#define _MESH_H_


#include "../Utils/Headers.h"


struct Vertex {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
};


class Mesh {
    public:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;

        Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
        ~Mesh();
        void Draw();

    private:
        GLuint VAO, VBO, EBO;

        void setupMesh();
};

#endif