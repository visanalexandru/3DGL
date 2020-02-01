//
// Created by gvisan on 01.02.2020.
//

#ifndef INC_3DGL_ACTORLOADER_H
#define INC_3DGL_ACTORLOADER_H

#include "ActorData.h"
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include<unordered_map>

namespace gl3d {

    class ActorLoader {

    private:
        static std::unordered_map<std::string, Node *> nodes;
        static int bone_count;


        static void processNode(aiNode *node, const aiScene *scene, MeshBuffer<skeletal_vertex> &data);

        static void
        processMesh(aiMesh *mesh, const aiScene *scene, MeshBuffer<skeletal_vertex> &data, int indices_offset);

        static glm::mat4 aiMatrix4x4ToGlm(const aiMatrix4x4 *from);


        static void createHierarchy(aiNode *node, Node *root);


    public:
        static ActorData load_actor(const std::string &path);
    };
}

#endif //INC_3DGL_ACTORLOADER_H
