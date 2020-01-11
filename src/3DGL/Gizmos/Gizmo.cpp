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

    void Gizmo::set_color(glm::vec3 newcolor) {
        gizmo_color = newcolor;
    }

}