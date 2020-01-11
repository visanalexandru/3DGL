//
// Created by gvisan on 11.01.2020.
//

#include "Container.h"


namespace gl3d {

    Container::Container(gl3d::AABB bounding_box, glm::vec3 color) : Gizmo(color) {
        set_position(bounding_box.AABB_position + bounding_box.AABB_dimension / 2.f);
        set_scale(bounding_box.AABB_dimension);
        create_cube_mesh();
    }

    void Container::create_cube_mesh() {
        MeshBuffer<simple_vertex> buffer;
        for (int i = 0; i < 6; i++) {
            MeshBuilder::add_cube_face(buffer, glm::vec3(0, 0, 0), i);
        }
        gizmo_mesh.set_data(buffer);
    }

}