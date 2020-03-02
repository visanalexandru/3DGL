//
// Created by gvisan on 01.02.2020.
//

#include<glm/gtx/quaternion.hpp>
#include "ActorLoader.h"

namespace gl3d {

    int ActorLoader::bone_count = 0;
    std::unordered_map<std::string, Node *>  ActorLoader::nodes;

    glm::mat4 ActorLoader::aiMatrix4x4ToGlm(const aiMatrix4x4 *from) {
        glm::mat4 to;
        to[0][0] = (GLfloat) from->a1;
        to[0][1] = (GLfloat) from->b1;
        to[0][2] = (GLfloat) from->c1;
        to[0][3] = (GLfloat) from->d1;
        to[1][0] = (GLfloat) from->a2;
        to[1][1] = (GLfloat) from->b2;
        to[1][2] = (GLfloat) from->c2;
        to[1][3] = (GLfloat) from->d2;
        to[2][0] = (GLfloat) from->a3;
        to[2][1] = (GLfloat) from->b3;
        to[2][2] = (GLfloat) from->c3;
        to[2][3] = (GLfloat) from->d3;
        to[3][0] = (GLfloat) from->a4;
        to[3][1] = (GLfloat) from->b4;
        to[3][2] = (GLfloat) from->c4;
        to[3][3] = (GLfloat) from->d4;
        return to;
    }

    Animation ActorLoader::loadAnimation(const aiScene *scene) {
        const aiAnimation *animation = scene->mAnimations[0];
        Animation to_return;
        to_return.ticks_per_second = animation->mTicksPerSecond;
        to_return.duration = animation->mDuration;

        for (unsigned i = 0; i < animation->mNumChannels; i++) {

            aiNodeAnim *here = animation->mChannels[i];
            Animation::AnimationNode node;
            node.name = here->mNodeName.data;

            for (unsigned k = 0; k < here->mNumPositionKeys; k++) {
                Animation::PositionFrame posframe;
                posframe.time = here->mPositionKeys[k].mTime;
                aiVector3D pos = here->mPositionKeys[k].mValue;
                posframe.position = glm::vec3(pos.x, pos.y, pos.z);

                node.position_frames.push_back(posframe);
            }

            for (unsigned k = 0; k < here->mNumRotationKeys; k++) {

                Animation::RotationFrame rotframe;
                rotframe.time = here->mRotationKeys[k].mTime;
                aiQuaternion rot = here->mRotationKeys[k].mValue;

                rotframe.rotation = glm::quat(rot.w, rot.x, rot.y, rot.z);

                node.rotation_frames.push_back(rotframe);
            }

            to_return.animation_nodes.push_back(node);
        }
        return to_return;
    }


    ActorData ActorLoader::load_actor(const std::string &path) {
        Assimp::Importer import;

        ActorData to_return;
        bone_count = 0;
        nodes.clear();

        MeshBuffer<skeletal_vertex> meshdata;

        Node *root = new Node();


        const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals);


        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            throw std::runtime_error(import.GetErrorString());
        }
        const aiAnimation *animation = scene->mAnimations[0];
        createHierarchy(scene->mRootNode, root);

        processNode(scene->mRootNode, scene, meshdata);

        to_return.mesh_data = meshdata;
        to_return.node_structure.set_structure(root);
        to_return.animation = loadAnimation(scene);

        delete root;
        return to_return;

    }

    void ActorLoader::createHierarchy(aiNode *node, Node *root) {

        nodes[node->mName.data] = root;
        root->name = node->mName.data;
        root->transformation = aiMatrix4x4ToGlm(&node->mTransformation);

        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            Node *newnode = new Node();
            root->children.push_back(newnode);

            createHierarchy(node->mChildren[i], newnode);
        }
    }


    void ActorLoader::processNode(aiNode *node, const aiScene *scene,
                                  MeshBuffer<skeletal_vertex> &data) {

        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
            processMesh(mesh, scene, data, data.vertices.size());
        }

        // then do the same for each of its children
        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene, data);
        }
    }

    void ActorLoader::processMesh(aiMesh *mesh, const aiScene *scene, MeshBuffer<skeletal_vertex> &data,
                                  int indices_offset) {


        std::vector<skeletal_vertex> local_vertices;
        for (int i = 0; i < mesh->mNumVertices; i++) {
            skeletal_vertex vertex;
            vertex.position.x = mesh->mVertices[i].x;
            vertex.position.y = mesh->mVertices[i].y;
            vertex.position.z = mesh->mVertices[i].z;

            if (mesh->HasNormals()) {
                vertex.normal.x = mesh->mNormals[i].x;
                vertex.normal.y = mesh->mNormals[i].y;
                vertex.normal.z = mesh->mNormals[i].z;
            }

            if (mesh->mTextureCoords[0]) {
                vertex.texture_coords.x = mesh->mTextureCoords[0][i].x;
                vertex.texture_coords.y = mesh->mTextureCoords[0][i].y;
            }

            local_vertices.push_back(vertex);
        }

        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                data.add_triangle_index(indices_offset + face.mIndices[j]);
        }

        for (unsigned i = 0; i < mesh->mNumBones; i++) {
            aiBone *here = mesh->mBones[i];
            Node *corresponding = nodes[here->mName.data];

            if (corresponding->boneid == -1) {
                corresponding->boneid = bone_count;
                corresponding->offset = aiMatrix4x4ToGlm(&here->mOffsetMatrix);
                bone_count++;
            }


            for (unsigned k = 0; k < here->mNumWeights; k++) {
                unsigned vertex_index = here->mWeights[k].mVertexId;
                local_vertices[vertex_index].add_bone(corresponding->boneid, here->mWeights[k].mWeight);
            }
        }
        data.vertices.insert(data.vertices.end(), local_vertices.begin(), local_vertices.end());

    }


}