//
// Created by gvisan on 31.07.2019.
//

#include "Skybox.h"


Skybox::Skybox(const ShaderProgram &program) : Drawable3D(program) {

    MeshBuffer<simple_vertex> buffer;
    for (int i = 0; i < 6; i++) {
        MeshBuilder::add_cube_face(buffer, glm::vec3(0, 0, 0), i);
    }
    cube_mesh.set_data(buffer);

    set_mesh(cube_mesh);


}