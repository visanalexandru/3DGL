//
// Created by gvisan on 11.01.2020.
//

#include "Gizmo.h"


namespace gl3d {
    Gizmo::Gizmo(glm::vec3 col) : gizmo_color(col) {

    }

    glm::vec3 Gizmo::get_color() const {
        return gizmo_color;
    }

    const Mesh &Gizmo::get_mesh() const {
        return gizmo_mesh;
    }

    glm::mat4 Gizmo::get_model_matrix() const {
        glm::mat4 to_return(1);
        to_return = glm::translate(to_return, position);
        to_return = glm::scale(to_return, scale);
        return to_return;
    }

    void Gizmo::set_position(glm::vec3 newpos) {
        position = newpos;
    }

    void Gizmo::set_scale(glm::vec3 newscale) {
        scale = newscale;
    }


    void Gizmo::set_color(glm::vec3 newcolor) {
        gizmo_color = newcolor;
    }

}