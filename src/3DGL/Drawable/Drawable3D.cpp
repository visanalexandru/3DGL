//
// Created by gvisan on 22.07.2019.
//

#include "Drawable3D.h"


const Mesh &Drawable3D::get_mesh() const {

    return mesh;

}

Drawable3D::Drawable3D(const ShaderProgram &shader) : shader_program(shader), texture(nullptr),
                                                      has_default_texture(true) {


    texture = new Texture2D();

}

void Drawable3D::set_texture(Texture &new_texture) {

    if (has_default_texture) {
        delete texture;
        has_default_texture = false;
    }
    texture = &new_texture;

}


Drawable3D::attributes Drawable3D::get_attributes() const {

    return attributes(texture->get_texture_index(), shader_program.get_shader_index());
}

const Texture &Drawable3D::get_texture() const {
    return *texture;

}

const ShaderProgram &Drawable3D::get_program() const {
    return shader_program;
}

unsigned Drawable3D::get_triangle_count() const {
    return mesh.get_triangle_count();

}

Drawable3D::~Drawable3D() {

    if (has_default_texture)
        delete texture;

}

Drawable3D::Drawable3D(const ShaderProgram &shader, glm::vec3 position) : Transformable(position),
                                                                          shader_program(shader), texture(nullptr),
                                                                          has_default_texture(true) {
    texture = new Texture2D();

}
