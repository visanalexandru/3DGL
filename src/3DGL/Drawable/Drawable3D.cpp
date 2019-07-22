//
// Created by gvisan on 22.07.2019.
//

#include "Drawable3D.h"


void Drawable3D::bind_mesh() const {

    mesh.bind_mesh();

}

Drawable3D::Drawable3D(const ShaderProgram &shader) : shader_program(shader) {


}

const ShaderProgram &Drawable3D::get_program() const {
    return shader_program;
}

unsigned Drawable3D::get_vertex_count() const {
    return mesh.get_vertex_count();

}

Drawable3D::Drawable3D(const ShaderProgram &shader, glm::vec3 position) : Transformable(position),
                                                                          shader_program(shader) {


}
