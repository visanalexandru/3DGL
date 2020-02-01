//
// Created by gvisan on 01.02.2020.
//

#include "Actor.h"


namespace gl3d {


    void Actor::set_shader_uniforms() const {
        get_program().setMat4v("gBones", bones, 100);
    }

    void Actor::update_bones(gl3d::Node *here, glm::mat4 transform) {
        glm::mat4 global_transform = transform * here->transformation;


        here->transformation = global_transform;

        if (here->boneid != -1) {
            here->transformation *= here->offset;
            bones[here->boneid] = here->transformation;
        }

        for (Node *child:here->children)
            update_bones(child, global_transform);

    }

    Actor::Actor(const ActorData &data) : Drawable3D() {
        set_shader_program(DefaultShaders::get_skinned_program());
        root_bone = data.root;
        update_bones(root_bone, glm::mat4(1));
        mesh.set_data(data.mesh_data);
        set_mesh(mesh);
    }


}