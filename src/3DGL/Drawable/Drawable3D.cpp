//
// Created by gvisan on 22.07.2019.
//

#include "Drawable3D.h"

namespace gl3d {
    const Mesh &Drawable3D::get_mesh() const {

        return *mesh;

    }

    Drawable3D::Drawable3D(const ShaderProgram &shader) : shader_program(shader), texture(nullptr), mesh(nullptr) {


    }

    void Drawable3D::set_texture(const Texture &new_texture) {

        texture = &new_texture;

    }


    void Drawable3D::set_rotation(glm::vec3 new_rotation) {

        rotation=new_rotation;
        update_local_bounds();

    }

    void Drawable3D::set_scale(glm::vec3 new_scale) {
        scale=new_scale;
        update_local_bounds();
    }


    void Drawable3D::update_local_bounds() {
        glm::mat4 scale_rotation(1);
        scale_rotation*=get_rotation_matrix();
        scale_rotation = glm::scale(scale_rotation, scale);



        auto bounds = get_mesh_bounds();

        glm::vec3 lower = bounds.first;
        glm::vec3 upper = bounds.second;

        glm::vec3 points[8];

        points[0] = lower;
        points[1] = glm::vec3(upper.x, lower.y, lower.z);
        points[2] = glm::vec3(upper.x, lower.y, upper.z);
        points[3] = glm::vec3(lower.x, lower.y, upper.z);

        points[4] = glm::vec3(lower.x, upper.y, lower.z);
        points[5] = glm::vec3(upper.x, upper.y, lower.z);
        points[6] = upper;
        points[7] = glm::vec3(lower.x, upper.y, upper.z);


        glm::vec3 min, max;

        for (int i = 0; i < 8; i++) {
            glm::vec4 here =scale_rotation * glm::vec4(points[i], 1);
            if (!i) {
                min = here;
                max = here;
            } else {
                min.x = std::min(min.x, here.x);
                min.y = std::min(min.y, here.y);
                min.z = std::min(min.z, here.z);

                max.x = std::max(max.x, here.x);
                max.y = std::max(max.y, here.y);
                max.z = std::max(max.z, here.z);
            }


        }


        glm::vec3 offset = max - min;

       local_bounding_box=AABB(min, offset);


    }

    void Drawable3D::set_mesh(const Mesh &new_mesh) {

        mesh = &new_mesh;
        update_local_bounds();

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

        AABB box(local_bounding_box.AABB_position+position,local_bounding_box.AABB_dimension);
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
}