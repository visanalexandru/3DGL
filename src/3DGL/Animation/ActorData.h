//
// Created by gvisan on 31.01.2020.
//

#ifndef INC_3DGL_ACTORDATA_H
#define INC_3DGL_ACTORDATA_H

#include "../Mesh/MeshBuffer.h"
#include "Animation.h"
#include <unordered_map>

namespace gl3d {

    struct Node {
        std::vector<Node *> children;
        glm::mat4 offset;
        glm::mat4 transformation;
        std::string name;
        int boneid;

        Node() : offset(1), transformation(1), boneid(-1) {//bone id inits to -1 because node might not be a bone

        }

        ~Node() {
            for (Node *a:children)
                delete a;
        }

        Node(const Node &other) {

            offset = other.offset;
            transformation = other.transformation;
            boneid = other.boneid;
            name = other.name;

            for (Node *a:other.children) {

                Node *newnode = new Node(*a);
                children.push_back(newnode);
            }
        }
    };

    class NodeStructure {
    private:
        Node *root;
        std::unordered_map<std::string, Node *> nodes;

        void set_names(Node *here) {
            nodes[here->name] = here;
            for (Node *a:here->children)
                set_names(a);
        }


    public:

        NodeStructure &operator=(const NodeStructure &other) {
            set_structure(other.get_root());
        }

        NodeStructure(const NodeStructure &other) {
            root = new Node(*other.get_root());
            set_names(root);
        }

        NodeStructure() : root(nullptr) {

        }

        void set_structure(const Node *structure_root) {
            delete root;
            nodes.clear();
            root = new Node(*structure_root);
            set_names(root);
        }

        const Node *get_root() const {
            return root;
        }

        void update_node(const std::string &name, glm::mat4 transformation) {
            nodes[name]->transformation = transformation;
        }

        ~NodeStructure() {
            delete root;
        }
    };


    struct ActorData {
        MeshBuffer <skeletal_vertex> mesh_data;
        NodeStructure node_structure;
        Animation animation;
    };


}


#endif //INC_3DGL_ACTORDATA_H



