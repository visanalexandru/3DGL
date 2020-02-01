//
// Created by gvisan on 31.01.2020.
//

#ifndef INC_3DGL_ACTORDATA_H
#define INC_3DGL_ACTORDATA_H

#include "../Mesh/MeshBuffer.h"

namespace gl3d {

    struct Node {
        std::vector<Node *> children;
        glm::mat4 offset;
        glm::mat4 transformation;
        int boneid;

        Node() : offset(1), transformation(1), boneid(-1) {//bone id inits to -1 because node might not be a bone

        }
    };


    struct ActorData {
        MeshBuffer<skeletal_vertex> mesh_data;
        Node *root;//the root node of the bone structure
    };


}


#endif //INC_3DGL_ACTORDATA_H



