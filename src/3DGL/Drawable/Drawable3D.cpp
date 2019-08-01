//
// Created by gvisan on 22.07.2019.
//

#include "Drawable3D.h"


const Mesh &Drawable3D::get_mesh() const {

    return *mesh;

}

Drawable3D::Drawable3D(const ShaderProgram &shader) : shader_program(shader), texture(nullptr), mesh(nullptr) {


}

void Drawable3D::set_texture(const Texture &new_texture) {

    texture = &new_texture;

}


void Drawable3D::set_mesh(const Mesh &new_mesh) {

    mesh = &new_mesh;

}

void Drawable3D::bind_texture() const {

    if (texture != nullptr) {
        texture->bind_texture();
    } else Texture::bind_empty_texture();


}

void Drawable3D::bind_mesh() const {

    if (mesh != nullptr) {

        mesh->bind_mesh();
    } else Mesh::bind_empty_mesh();


}


AABB Drawable3D::get_bounding_box() const {

    auto bounds = get_mesh_bounds();

    glm::vec4 rotated1 = get_model_matrix() * glm::vec4(bounds.first, 1);

    glm::vec4 rotated2 = get_model_matrix() * glm::vec4(bounds.second, 1);

    glm::vec3 lower(rotated1);
    glm::vec3 upper(rotated2);


    glm::vec3 a(std::min(lower.x, upper.x), std::min(lower.y, upper.y), std::min(lower.z, upper.z));
    glm::vec3 b(std::max(lower.x, upper.x), std::max(lower.y, upper.y), std::max(lower.z, upper.z));


    glm::vec3 offset = b - a;

    AABB box(a, offset);

    return box;


}


std::pair<glm::vec3, glm::vec3> Drawable3D::get_mesh_bounds() const {

    if (mesh != nullptr) {


        return mesh->get_dimensions();

    } else return {glm::vec3(0, 0, 0), glm::vec3(0, 0, 0)};

}

Drawable3D::attributes Drawable3D::get_attributes() const {

    unsigned texture_index = 0;

    if (texture != nullptr)
        texture_index = texture->get_texture_index();


    return attributes(texture_index, shader_program.get_shader_index());
}

const Texture &Drawable3D::get_texture() const {
    return *texture;

}

const ShaderProgram &Drawable3D::get_program() const {
    return shader_program;
}

unsigned Drawable3D::get_triangle_count() const {
    if (mesh != nullptr)
        return mesh->get_triangle_count();
    return 0;

}

Drawable3D::~Drawable3D() {


}

Drawable3D::Drawable3D(const ShaderProgram &shader, glm::vec3 position) : Transformable(position),
                                                                          shader_program(shader), texture(nullptr),
                                                                          mesh(nullptr) {

}
