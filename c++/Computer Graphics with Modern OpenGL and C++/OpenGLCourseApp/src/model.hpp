#ifndef MODEL_H_DEFINED
#define MODEL_H_DEFINED

#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.hpp"
#include "texture.hpp"

class Model
{
public:
    Model();

    void LoadModel(const std::string &);
    void RenderModel();
    void ClearModel();

    ~Model();

private:
    void LoadNode(aiNode *, const aiScene *); // store reference to a mesh
    void LoadMesh(aiMesh *, const aiScene *);
    void LoadMaterials(const aiScene *);

    std::vector<Mesh *> meshList;
    std::vector<Texture *> textureList;
    std::vector<unsigned int> meshToTex;
};

#endif