//
// Created by gvisan on 11.01.2020.
//

#include "Container.h"


namespace gl3d {

    Container::Container(glm::vec3 position, glm::vec3 size, glm::vec3 color) : Gizmo(color) {
        set_position(position);
        set_scale(size);
        create_cube_mesh();
    }

    Container::Container(gl3d::AABB aabb, glm::vec3 color) : Gizmo(color) {
        set_position(aabb.AABB_position + aabb.AABB_dimension / 2.f);
        set_scale(aabb.AABB_dimension);
        create_cube_mesh();
    }

    void Container::create_cube_mesh() {
        MeshBuffer<simple_vertex> buffer;
        for (int i = 0; i < 6; i++) {
            MeshBuilder::add_cube_face(buffer, glm::vec3(0, 0, 0), i);
        }
        gizmo_mesh.set_data(buffer);
    }

    AABB Container::get_bounding_box() const {
        return AABB(position - scale / 2.f, scale);
    }
}