//
// Created by gvisan on 31.07.2019.
//

#include "Skybox.h"

namespace gl3d {

    Skybox::Skybox(const Cubemap &cubemap) : text_cubemap(cubemap) {

        MeshBuffer<simple_vertex> buffer;
        for (int i = 0; i < 6; i++) {
            MeshBuilder::add_cube_face(buffer, glm::vec3(0, 0, 0), i);
        }
        cube_mesh.set_data(buffer);
    }


    void Skybox::bind_texture() const {
        text_cubemap.bind_cubemap();

    }

    void Skybox::bind_mesh() const {
        cube_mesh.bind_mesh();
    }

}


