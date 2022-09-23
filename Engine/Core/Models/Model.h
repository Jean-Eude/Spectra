#ifndef MODEL_H
#define MODEL_H

#include "../Utils/Headers.h"
#include "Mesh.h"


class Model 
{
    public:
        Model();
        ~Model();
        void loadModel(std::string path);
        void Draw();

    private:
        std::vector<Mesh> meshes;
        std::string directory;
        const aiScene* scene;

        void processNode(aiNode* node, const aiScene* scene);
        Mesh processMesh(aiMesh* mesh, const aiScene* scene);
};

#endif