//
// Created by gvisan on 01.02.2020.
//

#include "Actor.h"


namespace gl3d {


    void Actor::set_shader_uniforms() const {
        get_program().setMat4v("gBones", bones, 100);
    }

    void Actor::update_bones(const gl3d::Node *here, glm::mat4 transform) {
        glm::mat4 global_transform = transform * here->transformation;

        if (here->boneid != -1) {
            bones[here->boneid] = global_transform * here->offset;
        }

        for (Node *child:here->children)
            update_bones(child, global_transform);

    }

    Actor::Actor(const ActorData &data) : Drawable3D(), node_structure(data.node_structure) {
        set_shader_program(DefaultShaders::get_skinned_program());
        update_bones(node_structure.get_root(), glm::mat4(1));
        mesh.set_data(data.mesh_data);
        animation = data.animation;
        set_mesh(mesh);
    }

    void Actor::update_animation(float time) {

        int iteration = time / animation.duration;

        time -= iteration * animation.duration;

        for (Animation::AnimationNode node:animation.animation_nodes) {

            glm::vec3 pos = node.FindPosition(time);
            glm::quat rot = node.FindRotation(time);
            glm::mat4 transformation(1);
            transformation = glm::translate(transformation, pos);
            transformation = transformation * glm::mat4_cast(rot);

            node_structure.update_node(node.name, transformation);
        }
        update_bones(node_structure.get_root(), glm::mat4(1));

    }


}